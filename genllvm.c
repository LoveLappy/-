#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genllvm.h"

#define MAX_SYMBOLS 512
#define MAX_FUNCTIONS 128
#define MAX_LOOPS 32
#define MAX_DIMS 8
#define NAME_LEN 160
#define REPR_LEN 128

#define SYM_SCALAR 0
#define SYM_ARRAY 1

typedef struct {
    char name[NAME_LEN];
    char storage[NAME_LEN];
    int kind;
    int is_global;
    int is_const;
    int const_valid;
    int const_value;
    int dims[MAX_DIMS];
    int dim_count;
} Symbol;

typedef struct {
    char name[NAME_LEN];
    int returns_void;
    int param_count;
} FunctionInfo;

typedef struct {
    char continue_label[NAME_LEN];
    char end_label[NAME_LEN];
} LoopInfo;

typedef struct {
    char repr[REPR_LEN];
    int is_bool;
} Value;

typedef struct {
    char *result;
    int temp_count;
    int label_count;
    int terminated;
    int return_void;
    Symbol symbols[MAX_SYMBOLS];
    int symbol_count;
    int global_symbol_count;
    FunctionInfo functions[MAX_FUNCTIONS];
    int function_count;
    LoopInfo loops[MAX_LOOPS];
    int loop_depth;
    int use_putint;
    int use_getint;
} Generator;

static Generator g;

static int generate_module(past root, char *result);
static void gen_stmt(past node);
static void gen_expr_value(past node, Value *out);
static void gen_block(past node);

static int is_node(past node, const char *type)
{
    return node != NULL && node->nodeType != NULL && strcmp(node->nodeType, type) == 0;
}

static void fatal(const char *message)
{
    fprintf(stderr, "codegen error: %s\n", message);
    exit(1);
}

static void emit(const char *format, ...)
{
    char line[2048];
    va_list args;

    if (g.result == NULL) {
        fatal("output buffer is not initialized");
    }

    va_start(args, format);
    vsnprintf(line, sizeof(line), format, args);
    va_end(args);

    strcat(g.result, line);
    if (line[0] != '\0' && line[strlen(line) - 1] != '\n') {
        strcat(g.result, "\n");
    }
}

static void make_temp(char *out, size_t out_size)
{
    snprintf(out, out_size, "%%t%d", g.temp_count++);
}

static void make_label(const char *prefix, char *out, size_t out_size)
{
    snprintf(out, out_size, "%s.%d", prefix, g.label_count++);
}

static void sanitize_name(const char *source, char *out, size_t out_size)
{
    size_t i = 0;
    size_t j = 0;

    if (source == NULL || source[0] == '\0') {
        snprintf(out, out_size, "tmp");
        return;
    }

    while (source[i] != '\0' && j + 1 < out_size) {
        unsigned char ch = (unsigned char)source[i++];
        if (isalnum(ch) || ch == '_') {
            out[j++] = (char)ch;
        } else {
            out[j++] = '_';
        }
    }
    out[j] = '\0';
}

static Symbol *symbol_add(const char *name, const char *storage, int kind,
                          int is_global, int is_const)
{
    Symbol *symbol;

    if (g.symbol_count >= MAX_SYMBOLS || name == NULL || storage == NULL) {
        fatal("too many variables");
    }

    symbol = &g.symbols[g.symbol_count++];
    memset(symbol, 0, sizeof(*symbol));
    snprintf(symbol->name, sizeof(symbol->name), "%s", name);
    snprintf(symbol->storage, sizeof(symbol->storage), "%s", storage);
    symbol->kind = kind;
    symbol->is_global = is_global;
    symbol->is_const = is_const;
    return symbol;
}

static Symbol *symbol_find(const char *name)
{
    int i;

    if (name == NULL) {
        return NULL;
    }
    for (i = g.symbol_count - 1; i >= 0; --i) {
        if (strcmp(g.symbols[i].name, name) == 0) {
            return &g.symbols[i];
        }
    }
    return NULL;
}

static FunctionInfo *function_find(const char *name)
{
    int i;

    for (i = 0; i < g.function_count; ++i) {
        if (strcmp(g.functions[i].name, name) == 0) {
            return &g.functions[i];
        }
    }
    return NULL;
}

static past list_head(past list)
{
    return list == NULL ? NULL : list->left;
}

static past list_next(past node)
{
    return node == NULL ? NULL : node->next;
}

static int eval_const(past node, int *value)
{
    int left;
    int right;

    if (node == NULL) {
        return 0;
    }
    if (is_node(node, "intValue")) {
        *value = node->ivalue;
        return 1;
    }
    if (is_node(node, "parameter")) {
        Symbol *symbol = symbol_find(node->strValue);
        if (symbol != NULL && symbol->const_valid) {
            *value = symbol->const_value;
            return 1;
        }
        return 0;
    }
    if (is_node(node, "UnaryExp") && node->left != NULL) {
        return eval_const(node->left, value);
    }
    if (is_node(node, "expr")) {
        if (node->left == NULL && node->right != NULL && node->strValue != NULL &&
            strcmp(node->strValue, "@") == 0) {
            if (!eval_const(node->right, &right)) {
                return 0;
            }
            if (node->ivalue == '+') {
                *value = right;
                return 1;
            }
            if (node->ivalue == '-') {
                *value = -right;
                return 1;
            }
            if (node->ivalue == '!') {
                *value = !right;
                return 1;
            }
        }

        if (!eval_const(node->left, &left) || !eval_const(node->right, &right)) {
            return 0;
        }

        if (node->strValue != NULL && strcmp(node->strValue, "@") == 0) {
            switch (node->ivalue) {
            case '+': *value = left + right; return 1;
            case '-': *value = left - right; return 1;
            case '*': *value = left * right; return 1;
            case '/': if (right != 0) { *value = left / right; return 1; } return 0;
            case '%': if (right != 0) { *value = left % right; return 1; } return 0;
            case '<': *value = left < right; return 1;
            case '>': *value = left > right; return 1;
            default: return 0;
            }
        }
        if (node->strValue != NULL && strcmp(node->strValue, "<=") == 0) {
            *value = left <= right;
            return 1;
        }
        if (node->strValue != NULL && strcmp(node->strValue, ">=") == 0) {
            *value = left >= right;
            return 1;
        }
        if (node->strValue != NULL && strcmp(node->strValue, "==") == 0) {
            *value = left == right;
            return 1;
        }
        if (node->strValue != NULL && strcmp(node->strValue, "!=") == 0) {
            *value = left != right;
            return 1;
        }
        if (node->strValue != NULL && strcmp(node->strValue, "&&") == 0) {
            *value = left && right;
            return 1;
        }
        if (node->strValue != NULL && strcmp(node->strValue, "||") == 0) {
            *value = left || right;
            return 1;
        }
    }
    return 0;
}

static void make_array_type(const int *dims, int dim_count, char *out, size_t out_size)
{
    char nested[NAME_LEN];
    int i;

    nested[0] = '\0';
    for (i = dim_count - 1; i >= 0; --i) {
        char part[NAME_LEN + 32];
        if (nested[0] == '\0') {
            snprintf(part, sizeof(part), "[%d x i32]", dims[i]);
        } else {
            snprintf(part, sizeof(part), "[%d x %s]", dims[i], nested);
        }
        snprintf(nested, sizeof(nested), "%s", part);
    }
    snprintf(out, out_size, "%s", nested[0] == '\0' ? "i32" : nested);
}

static int parse_dims(past def, int dims[MAX_DIMS], int *dim_count)
{
    past holder;
    past dim_list;
    past item;
    int count = 0;

    *dim_count = 0;
    if (def == NULL || def->left == NULL) {
        return 0;
    }
    holder = def->left;
    if (is_node(holder, "parameter")) {
        return 0;
    }
    if (!is_node(holder, "VarDef_para") && !is_node(holder, "ConstDef_para")) {
        return 0;
    }

    dim_list = holder->left == NULL ? NULL : holder->left->next;
    item = list_head(dim_list);
    while (item != NULL && count < MAX_DIMS) {
        int value;
        if (!eval_const(item, &value) || value <= 0) {
            value = 1;
        }
        dims[count++] = value;
        item = list_next(item);
    }
    *dim_count = count;
    return count > 0;
}

static const char *definition_name(past def)
{
    past holder;

    if (def == NULL || def->left == NULL) {
        return NULL;
    }
    holder = def->left;
    if (is_node(holder, "parameter")) {
        return holder->strValue;
    }
    if ((is_node(holder, "VarDef_para") || is_node(holder, "ConstDef_para")) &&
        holder->left != NULL) {
        return holder->left->strValue;
    }
    return NULL;
}

static int collect_init_values(past node, int *values, int max_values, int *count)
{
    past item;

    if (node == NULL) {
        return 1;
    }
    if (is_node(node, "InitVal_list") || is_node(node, "ConstInitVal_list")) {
        item = list_head(node);
        while (item != NULL) {
            if (!collect_init_values(item, values, max_values, count)) {
                return 0;
            }
            item = list_next(item);
        }
        return 1;
    }
    if (is_node(node, "InitVal_empty") || is_node(node, "ConstInitVal_empty")) {
        return 1;
    }
    if (*count >= max_values) {
        return 0;
    }
    if (eval_const(node, &values[*count])) {
        (*count)++;
        return 1;
    }
    return 0;
}

static const char *function_name(past node)
{
    past para;

    if (node == NULL || node->left == NULL) {
        return NULL;
    }
    para = node->left;
    if (para->left == NULL || para->left->next == NULL) {
        return NULL;
    }
    return para->left->next->strValue;
}

static const char *function_return_type(past node)
{
    if (node == NULL || node->left == NULL || node->left->left == NULL) {
        return "int";
    }
    return node->left->left->strValue;
}

static past function_param_list(past node)
{
    past para;
    past id;

    if (node == NULL || node->left == NULL) {
        return NULL;
    }
    para = node->left;
    if (para->left == NULL || para->left->next == NULL) {
        return NULL;
    }
    id = para->left->next;
    return id->left;
}

static void collect_functions(past root)
{
    past item;

    if (is_node(root, "CompUnit")) {
        item = list_head(root);
    } else {
        item = root;
    }

    while (item != NULL) {
        if (is_node(item, "FuncDef")) {
            FunctionInfo *function;
            past params;
            if (g.function_count >= MAX_FUNCTIONS) {
                fatal("too many functions");
            }
            function = &g.functions[g.function_count++];
            memset(function, 0, sizeof(*function));
            snprintf(function->name, sizeof(function->name), "%s", function_name(item));
            function->returns_void = strcmp(function_return_type(item), "void") == 0;
            params = function_param_list(item);
            function->param_count = params == NULL ? 0 : params->ivalue;
        }
        item = list_next(item);
    }
}

static void scan_calls(past node)
{
    if (node == NULL) {
        return;
    }
    if (is_node(node, "UnaryExp") && node->left != NULL &&
        is_node(node->left, "parameter") && node->left->strValue != NULL) {
        if (strcmp(node->left->strValue, "putint") == 0 &&
            function_find("putint") == NULL) {
            g.use_putint = 1;
        }
        if (strcmp(node->left->strValue, "getint") == 0 &&
            function_find("getint") == NULL) {
            g.use_getint = 1;
        }
    }
    scan_calls(node->left);
    scan_calls(node->right);
    scan_calls(node->next);
}

static void prepare_globals(past root)
{
    past item;

    item = is_node(root, "CompUnit") ? list_head(root) : root;
    while (item != NULL) {
        if (is_node(item, "Decl") && item->left != NULL) {
            past decl = item->left;
            int is_const = is_node(decl, "ConstDecl");
            past def = list_head(decl->right);

            while (def != NULL) {
                const char *name = definition_name(def);
                char storage[NAME_LEN];
                int dims[MAX_DIMS];
                int dim_count;
                Symbol *symbol;

                if (name == NULL) {
                    def = list_next(def);
                    continue;
                }
                snprintf(storage, sizeof(storage), "@%s", name);
                if (symbol_find(name) == NULL) {
                    symbol = symbol_add(name, storage, SYM_SCALAR, 1, is_const);
                    if (parse_dims(def, dims, &dim_count)) {
                        symbol->kind = SYM_ARRAY;
                        symbol->dim_count = dim_count;
                        memcpy(symbol->dims, dims, sizeof(dims));
                    } else {
                        int value;
                        if (def->right != NULL && eval_const(def->right, &value)) {
                            symbol->const_valid = 1;
                            symbol->const_value = value;
                        }
                    }
                }
                def = list_next(def);
            }
        }
        item = list_next(item);
    }
    g.global_symbol_count = g.symbol_count;
}

static void emit_global_decl(past decl_node)
{
    past decl = decl_node->left;
    int is_const;
    past def;

    if (decl == NULL) {
        return;
    }
    is_const = is_node(decl, "ConstDecl");
    def = list_head(decl->right);
    while (def != NULL) {
        const char *name = definition_name(def);
        Symbol *symbol = symbol_find(name);
        int dims[MAX_DIMS];
        int dim_count;
        int is_array;

        if (symbol == NULL) {
            def = list_next(def);
            continue;
        }
        is_array = parse_dims(def, dims, &dim_count);
        if (!is_array) {
            int value = 0;
            if (def->right != NULL) {
                (void)eval_const(def->right, &value);
            }
            emit("@%s = %s i32 %d, align 4", name,
                 is_const ? "constant" : "global", value);
        } else {
            char type[NAME_LEN];
            char line[4096];
            int values[128];
            int count = 0;
            int i;
            int total = 1;

            make_array_type(dims, dim_count, type, sizeof(type));
            for (i = 0; i < dim_count; ++i) {
                total *= dims[i];
            }
            if (def->right != NULL) {
                (void)collect_init_values(def->right, values, 128, &count);
            }
            if (dim_count == 1 && count > 0) {
                snprintf(line, sizeof(line), "@%s = %s %s [", name,
                         is_const ? "constant" : "global", type);
                for (i = 0; i < total && i < 128; ++i) {
                    char part[NAME_LEN + 32];
                    int value = i < count ? values[i] : 0;
                    snprintf(part, sizeof(part), "%si32 %d", i == 0 ? "" : ", ", value);
                    strncat(line, part, sizeof(line) - strlen(line) - 1);
                }
                strncat(line, "], align 16", sizeof(line) - strlen(line) - 1);
                emit("%s", line);
            } else {
                emit("@%s = %s %s zeroinitializer, align 16", name,
                     is_const ? "constant" : "global", type);
            }
        }
        def = list_next(def);
    }
}

static void make_local_storage(const char *name, char *out, size_t out_size)
{
    char clean[NAME_LEN];
    sanitize_name(name, clean, sizeof(clean));
    snprintf(out, out_size, "%%v_%s_%d", clean, g.symbol_count);
}

static void gen_array_init(Symbol *symbol, past init)
{
    int values[128];
    int count = 0;
    int total;
    int i;
    char type[NAME_LEN];

    if (symbol == NULL || init == NULL || symbol->dim_count != 1) {
        return;
    }
    make_array_type(symbol->dims, symbol->dim_count, type, sizeof(type));
    total = symbol->dims[0];
    if (!collect_init_values(init, values, 128, &count)) {
        return;
    }
    for (i = 0; i < total && i < count; ++i) {
        char pointer[REPR_LEN];
        make_temp(pointer, sizeof(pointer));
        emit("  %s = getelementptr inbounds %s, %s* %s, i64 0, i64 %d",
             pointer, type, type, symbol->storage, i);
        emit("  store i32 %d, i32* %s, align 4", values[i], pointer);
    }
}

static void gen_decl(past decl_node)
{
    past decl = decl_node->left;
    int is_const;
    past def;

    if (decl == NULL) {
        return;
    }
    is_const = is_node(decl, "ConstDecl");
    def = list_head(decl->right);
    while (def != NULL && !g.terminated) {
        const char *name = definition_name(def);
        char storage[NAME_LEN];
        int dims[MAX_DIMS];
        int dim_count;
        Symbol *symbol;

        if (name == NULL) {
            def = list_next(def);
            continue;
        }
        make_local_storage(name, storage, sizeof(storage));
        if (parse_dims(def, dims, &dim_count)) {
            char type[NAME_LEN];
            make_array_type(dims, dim_count, type, sizeof(type));
            symbol = symbol_add(name, storage, SYM_ARRAY, 0, is_const);
            symbol->dim_count = dim_count;
            memcpy(symbol->dims, dims, sizeof(dims));
            emit("  %s = alloca %s, align 16", storage, type);
            gen_array_init(symbol, def->right);
        } else {
            Value value;
            symbol = symbol_add(name, storage, SYM_SCALAR, 0, is_const);
            if (def->right != NULL) {
                int constant_value;
                if (eval_const(def->right, &constant_value)) {
                    symbol->const_valid = 1;
                    symbol->const_value = constant_value;
                }
            }
            emit("  %s = alloca i32, align 4", storage);
            if (def->right != NULL) {
                gen_expr_value(def->right, &value);
                emit("  store i32 %s, i32* %s, align 4", value.repr, storage);
            }
        }
        def = list_next(def);
    }
}

static void value_to_i32(Value *value)
{
    char temp[REPR_LEN];

    if (!value->is_bool) {
        return;
    }
    make_temp(temp, sizeof(temp));
    emit("  %s = zext i1 %s to i32", temp, value->repr);
    snprintf(value->repr, sizeof(value->repr), "%s", temp);
    value->is_bool = 0;
}

static void value_to_i1(Value *value)
{
    char temp[REPR_LEN];

    if (value->is_bool) {
        return;
    }
    make_temp(temp, sizeof(temp));
    emit("  %s = icmp ne i32 %s, 0", temp, value->repr);
    snprintf(value->repr, sizeof(value->repr), "%s", temp);
    value->is_bool = 1;
}

static void gen_condition(past node, char *out, size_t out_size)
{
    Value value;

    gen_expr_value(node, &value);
    value_to_i1(&value);
    snprintf(out, out_size, "%s", value.repr);
}

static void gen_array_address(past node, char *out, size_t out_size)
{
    Symbol *symbol;
    past index_node;
    char indices[512];
    char type[NAME_LEN];
    char temp[REPR_LEN];
    int count = 0;

    out[0] = '\0';
    if (!is_node(node, "LVal_SEG") || node->left == NULL) {
        return;
    }
    symbol = symbol_find(node->left->strValue);
    if (symbol == NULL || symbol->kind != SYM_ARRAY) {
        return;
    }

    make_array_type(symbol->dims, symbol->dim_count, type, sizeof(type));
    indices[0] = '\0';
    index_node = list_head(node->right);
    while (index_node != NULL && count < symbol->dim_count) {
        Value index;
        char part[REPR_LEN + 32];
        gen_expr_value(index_node, &index);
        value_to_i32(&index);
        snprintf(part, sizeof(part), "%si64 %s", count == 0 ? "" : ", ", index.repr);
        strncat(indices, part, sizeof(indices) - strlen(indices) - 1);
        count++;
        index_node = list_next(index_node);
    }
    if (count == 0) {
        return;
    }

    make_temp(temp, sizeof(temp));
    emit("  %s = getelementptr inbounds %s, %s* %s, i64 0, %s",
         temp, type, type, symbol->storage, indices);
    snprintf(out, out_size, "%s", temp);
}

static void gen_lvalue_address(past node, char *out, size_t out_size)
{
    Symbol *symbol;

    out[0] = '\0';
    if (node == NULL) {
        return;
    }
    if (is_node(node, "LVal_SEG")) {
        gen_array_address(node, out, out_size);
        return;
    }
    if (is_node(node, "parameter")) {
        symbol = symbol_find(node->strValue);
        if (symbol != NULL && symbol->kind == SYM_SCALAR) {
            snprintf(out, out_size, "%s", symbol->storage);
        }
    }
}

static void gen_call(past node, Value *out)
{
    const char *name;
    FunctionInfo *info;
    past args;
    char argument_list[1024];
    char temp[REPR_LEN];
    int returns_void;

    if (node->left == NULL || !is_node(node->left, "parameter")) {
        snprintf(out->repr, sizeof(out->repr), "0");
        out->is_bool = 0;
        return;
    }
    name = node->left->strValue;
    info = function_find(name);
    returns_void = (info != NULL) ? info->returns_void :
                   (strcmp(name, "putint") == 0);

    argument_list[0] = '\0';
    args = list_head(node->right);
    while (args != NULL) {
        Value value;
        char part[REPR_LEN + 32];
        gen_expr_value(args, &value);
        value_to_i32(&value);
        snprintf(part, sizeof(part), "%si32 %s",
                 argument_list[0] == '\0' ? "" : ", ", value.repr);
        strncat(argument_list, part, sizeof(argument_list) - strlen(argument_list) - 1);
        args = list_next(args);
    }

    if (returns_void) {
        emit("  call void @%s(%s)", name, argument_list);
        snprintf(out->repr, sizeof(out->repr), "0");
        out->is_bool = 0;
    } else {
        make_temp(temp, sizeof(temp));
        emit("  %s = call i32 @%s(%s)", temp, name, argument_list);
        snprintf(out->repr, sizeof(out->repr), "%s", temp);
        out->is_bool = 0;
    }
}

static void gen_expr_value(past node, Value *out)
{
    out->repr[0] = '\0';
    out->is_bool = 0;

    if (node == NULL) {
        snprintf(out->repr, sizeof(out->repr), "0");
        return;
    }

    if (is_node(node, "intValue")) {
        snprintf(out->repr, sizeof(out->repr), "%d", node->ivalue);
        return;
    }

    if (is_node(node, "parameter")) {
        Symbol *symbol = symbol_find(node->strValue);
        char temp[REPR_LEN];
        if (symbol == NULL || symbol->kind == SYM_ARRAY) {
            snprintf(out->repr, sizeof(out->repr), "0");
            return;
        }
        make_temp(temp, sizeof(temp));
        emit("  %s = load i32, i32* %s, align 4", temp, symbol->storage);
        snprintf(out->repr, sizeof(out->repr), "%s", temp);
        return;
    }

    if (is_node(node, "LVal_SEG")) {
        char pointer[REPR_LEN];
        char temp[REPR_LEN];
        gen_array_address(node, pointer, sizeof(pointer));
        if (pointer[0] == '\0') {
            snprintf(out->repr, sizeof(out->repr), "0");
            return;
        }
        make_temp(temp, sizeof(temp));
        emit("  %s = load i32, i32* %s, align 4", temp, pointer);
        snprintf(out->repr, sizeof(out->repr), "%s", temp);
        return;
    }

    if (is_node(node, "UnaryExp")) {
        if (node->left != NULL && is_node(node->left, "parameter")) {
            gen_call(node, out);
            return;
        }
        if (node->left != NULL) {
            gen_expr_value(node->left, out);
        } else {
            snprintf(out->repr, sizeof(out->repr), "0");
        }
        return;
    }

    if (is_node(node, "expr")) {
        Value left;
        Value right;
        char temp[REPR_LEN];

        if (node->left == NULL && node->right != NULL) {
            gen_expr_value(node->right, &right);
            if (node->ivalue == '+') {
                *out = right;
                return;
            }
            if (node->ivalue == '-') {
                value_to_i32(&right);
                make_temp(temp, sizeof(temp));
                emit("  %s = sub i32 0, %s", temp, right.repr);
                snprintf(out->repr, sizeof(out->repr), "%s", temp);
                out->is_bool = 0;
                return;
            }
            if (node->ivalue == '!') {
                value_to_i1(&right);
                make_temp(temp, sizeof(temp));
                emit("  %s = xor i1 %s, true", temp, right.repr);
                snprintf(out->repr, sizeof(out->repr), "%s", temp);
                out->is_bool = 1;
                return;
            }
        }

        gen_expr_value(node->left, &left);
        gen_expr_value(node->right, &right);

        if (node->strValue != NULL && strcmp(node->strValue, "@") == 0) {
            if (node->ivalue == '+' || node->ivalue == '-' ||
                node->ivalue == '*' || node->ivalue == '/' || node->ivalue == '%' ||
                node->ivalue == '<' || node->ivalue == '>') {
                const char *op = NULL;
                value_to_i32(&left);
                value_to_i32(&right);
                switch (node->ivalue) {
                case '+': op = "add"; break;
                case '-': op = "sub"; break;
                case '*': op = "mul"; break;
                case '/': op = "sdiv"; break;
                case '%': op = "srem"; break;
                case '<': op = "icmp slt"; break;
                case '>': op = "icmp sgt"; break;
                default: break;
                }
                make_temp(temp, sizeof(temp));
                emit("  %s = %s i32 %s, %s", temp, op, left.repr, right.repr);
                snprintf(out->repr, sizeof(out->repr), "%s", temp);
                out->is_bool = (node->ivalue == '<' || node->ivalue == '>');
                return;
            }
        } else if (node->strValue != NULL) {
            const char *predicate = NULL;
            if (strcmp(node->strValue, "<=") == 0) predicate = "sle";
            else if (strcmp(node->strValue, ">=") == 0) predicate = "sge";
            else if (strcmp(node->strValue, "==") == 0) predicate = "eq";
            else if (strcmp(node->strValue, "!=") == 0) predicate = "ne";

            if (predicate != NULL) {
                value_to_i32(&left);
                value_to_i32(&right);
                make_temp(temp, sizeof(temp));
                emit("  %s = icmp %s i32 %s, %s", temp, predicate,
                     left.repr, right.repr);
                snprintf(out->repr, sizeof(out->repr), "%s", temp);
                out->is_bool = 1;
                return;
            }

            if (strcmp(node->strValue, "&&") == 0 ||
                strcmp(node->strValue, "||") == 0) {
                value_to_i1(&left);
                value_to_i1(&right);
                make_temp(temp, sizeof(temp));
                emit("  %s = %s i1 %s, %s", temp,
                     strcmp(node->strValue, "&&") == 0 ? "and" : "or",
                     left.repr, right.repr);
                snprintf(out->repr, sizeof(out->repr), "%s", temp);
                out->is_bool = 1;
                return;
            }
        }
    }

    snprintf(out->repr, sizeof(out->repr), "0");
}

static void gen_assign(past node)
{
    Value value;
    char pointer[REPR_LEN];

    if (node == NULL || node->left == NULL) {
        return;
    }
    gen_lvalue_address(node->left, pointer, sizeof(pointer));
    if (pointer[0] == '\0') {
        return;
    }
    gen_expr_value(node->right, &value);
    value_to_i32(&value);
    emit("  store i32 %s, i32* %s, align 4", value.repr, pointer);
}

static void gen_if(past node)
{
    char then_label[NAME_LEN];
    char else_label[NAME_LEN];
    char end_label[NAME_LEN];
    char condition[REPR_LEN];
    int then_terminated;
    int else_terminated;
    int has_else = is_node(node, "IfElse_Stmt");

    gen_condition(node->left, condition, sizeof(condition));
    make_label("if.then", then_label, sizeof(then_label));
    make_label("if.else", else_label, sizeof(else_label));
    make_label("if.end", end_label, sizeof(end_label));

    if (has_else) {
        emit("  br i1 %s, label %%%s, label %%%s", condition,
             then_label, else_label);
    } else {
        emit("  br i1 %s, label %%%s, label %%%s", condition,
             then_label, end_label);
    }

    emit("%s:", then_label);
    g.terminated = 0;
    if (has_else) {
        gen_stmt(node->right->left);
    } else {
        gen_stmt(node->right);
    }
    then_terminated = g.terminated;
    if (!then_terminated) {
        emit("  br label %%%s", end_label);
    }

    if (has_else) {
        emit("%s:", else_label);
        g.terminated = 0;
        gen_stmt(node->right->left->next);
        else_terminated = g.terminated;
        if (!else_terminated) {
            emit("  br label %%%s", end_label);
        }
        if (!then_terminated || !else_terminated) {
            emit("%s:", end_label);
            g.terminated = 0;
        } else {
            g.terminated = 1;
        }
    } else {
        emit("%s:", end_label);
        g.terminated = 0;
    }
}

static void gen_while(past node)
{
    char cond_label[NAME_LEN];
    char body_label[NAME_LEN];
    char end_label[NAME_LEN];
    char condition[REPR_LEN];

    make_label("while.cond", cond_label, sizeof(cond_label));
    make_label("while.body", body_label, sizeof(body_label));
    make_label("while.end", end_label, sizeof(end_label));

    emit("  br label %%%s", cond_label);
    emit("%s:", cond_label);
    gen_condition(node->left, condition, sizeof(condition));
    emit("  br i1 %s, label %%%s, label %%%s", condition, body_label, end_label);

    emit("%s:", body_label);
    if (g.loop_depth >= MAX_LOOPS) {
        fatal("too many nested loops");
    }
    snprintf(g.loops[g.loop_depth].continue_label,
             sizeof(g.loops[g.loop_depth].continue_label), "%s", cond_label);
    snprintf(g.loops[g.loop_depth].end_label,
             sizeof(g.loops[g.loop_depth].end_label), "%s", end_label);
    g.loop_depth++;
    g.terminated = 0;
    gen_stmt(node->right);
    g.loop_depth--;
    if (!g.terminated) {
        emit("  br label %%%s", cond_label);
    }

    emit("%s:", end_label);
    g.terminated = 0;
}

static void gen_return(past node)
{
    if (node == NULL || node->left == NULL) {
        if (g.return_void) {
            emit("  ret void");
        } else {
            emit("  ret i32 0");
        }
    } else {
        Value value;
        gen_expr_value(node->left, &value);
        if (g.return_void) {
            emit("  ret void");
        } else {
            value_to_i32(&value);
            emit("  ret i32 %s", value.repr);
        }
    }
    g.terminated = 1;
}

static void gen_stmt(past node)
{
    if (node == NULL || g.terminated) {
        return;
    }
    if (is_node(node, "Block_list")) {
        gen_block(node);
    } else if (is_node(node, "Block_empty") || is_node(node, "Stmt_empty")) {
        return;
    } else if (is_node(node, "Decl")) {
        gen_decl(node);
    } else if (is_node(node, "Assign_Stmt")) {
        gen_assign(node);
    } else if (is_node(node, "If_Stmt") || is_node(node, "IfElse_Stmt")) {
        gen_if(node);
    } else if (is_node(node, "While_Stmt")) {
        gen_while(node);
    } else if (is_node(node, "Return_Stmt")) {
        gen_return(node);
    } else if (is_node(node, "Break_Stmt")) {
        if (g.loop_depth > 0) {
            emit("  br label %%%s", g.loops[g.loop_depth - 1].end_label);
            g.terminated = 1;
        }
    } else if (is_node(node, "Continue_Stmt")) {
        if (g.loop_depth > 0) {
            emit("  br label %%%s", g.loops[g.loop_depth - 1].continue_label);
            g.terminated = 1;
        }
    } else {
        Value ignored;
        gen_expr_value(node, &ignored);
    }
}

static void gen_block(past node)
{
    past item;
    int saved_symbols;

    if (node == NULL || is_node(node, "Block_empty")) {
        return;
    }
    saved_symbols = g.symbol_count;
    item = list_head(node);
    while (item != NULL && !g.terminated) {
        gen_stmt(item);
        item = list_next(item);
    }
    g.symbol_count = saved_symbols;
}

static void gen_function(past node)
{
    const char *name = function_name(node);
    const char *return_type = function_return_type(node);
    past params = function_param_list(node);
    past param;
    char parameter_text[1024];
    int saved_symbols = g.symbol_count;
    int first = 1;

    if (name == NULL) {
        return;
    }

    g.temp_count = 1;
    g.label_count = 1;
    g.terminated = 0;
    g.return_void = strcmp(return_type, "void") == 0;
    g.loop_depth = 0;

    parameter_text[0] = '\0';
    param = params == NULL ? NULL : list_head(params);
    while (param != NULL) {
        past holder = param->left;
        past id = NULL;
        if (holder != NULL && holder->left != NULL) {
            id = holder->left->next;
        }
        if (id != NULL) {
            char clean[NAME_LEN];
            char part[REPR_LEN];
            sanitize_name(id->strValue, clean, sizeof(clean));
            snprintf(part, sizeof(part), "%si32 %%p_%s",
                     first ? "" : ", ", clean);
            strncat(parameter_text, part,
                    sizeof(parameter_text) - strlen(parameter_text) - 1);
            first = 0;
        }
        param = list_next(param);
    }

    emit("define %s @%s(%s) {", g.return_void ? "void" : "i32",
         name, parameter_text);
    emit("entry:");

    param = params == NULL ? NULL : list_head(params);
    while (param != NULL) {
        past holder = param->left;
        past id = NULL;
        if (holder != NULL && holder->left != NULL) {
            id = holder->left->next;
        }
        if (id != NULL) {
            char clean[NAME_LEN];
            char storage[NAME_LEN];
            sanitize_name(id->strValue, clean, sizeof(clean));
            make_local_storage(id->strValue, storage, sizeof(storage));
            symbol_add(id->strValue, storage, SYM_SCALAR, 0, 0);
            emit("  %s = alloca i32, align 4", storage);
            emit("  store i32 %%p_%s, i32* %s, align 4", clean, storage);
        }
        param = list_next(param);
    }

    gen_block(node->right);
    if (!g.terminated) {
        if (g.return_void) {
            emit("  ret void");
        } else {
            emit("  ret i32 0");
        }
    }
    emit("}");
    g.symbol_count = saved_symbols;
}

static int generate_module(past root, char *result)
{
    past item;

    memset(&g, 0, sizeof(g));
    g.result = result;
    result[0] = '\0';

    if (is_node(root, "Block_list")) {
        g.temp_count = 1;
        g.label_count = 1;
        g.return_void = 0;
        emit("define i32 @main() {");
        emit("entry:");
        gen_block(root);
        if (!g.terminated) {
            emit("  ret i32 0");
        }
        emit("}");
        return 0;
    }

    collect_functions(root);
    prepare_globals(root);
    scan_calls(root);

    if (g.use_putint) {
        emit("declare void @putint(i32)");
    }
    if (g.use_getint) {
        emit("declare i32 @getint()");
    }

    item = is_node(root, "CompUnit") ? list_head(root) : root;
    while (item != NULL) {
        if (is_node(item, "Decl")) {
            emit_global_decl(item);
        }
        item = list_next(item);
    }

    item = is_node(root, "CompUnit") ? list_head(root) : root;
    while (item != NULL) {
        if (is_node(item, "FuncDef")) {
            gen_function(item);
        }
        item = list_next(item);
    }
    return 0;
}

int genExpr(past node)
{
    char *buffer;
    int rc;

    if (node == NULL) {
        fprintf(stderr, "empty AST\n");
        return -1;
    }

    buffer = (char *)calloc(1, 32u * 1024u * 1024u);
    if (buffer == NULL) {
        fprintf(stderr, "run out of memory.\n");
        return -1;
    }
    rc = generate_module(node, buffer);
    printf("%s", buffer);
    free(buffer);
    return rc;
}

static void ensure_standalone_context(char *result)
{
    if (g.result != result) {
        g.result = result;
        g.temp_count = 1;
        g.label_count = 1;
        result[0] = '\0';
    }
}

int genArithmeticExpr(past node, char *result)
{
    Value value;
    ensure_standalone_context(result);
    gen_expr_value(node, &value);
    return 0;
}

int genLogicExpr(past node, char *result)
{
    char condition[REPR_LEN];
    ensure_standalone_context(result);
    gen_condition(node, condition, sizeof(condition));
    return 0;
}

int genAssignStmt(past node, char *result)
{
    ensure_standalone_context(result);
    gen_assign(node);
    return 0;
}

int genIfStmt(past node, char *result)
{
    ensure_standalone_context(result);
    gen_if(node);
    return 0;
}

int genWhileStmt(past node, char *result)
{
    ensure_standalone_context(result);
    gen_while(node);
    return 0;
}


