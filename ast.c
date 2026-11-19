#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *copy_string(const char *value)
{
    size_t len;
    char *copy;

    if (value == NULL) {
        return NULL;
    }

    len = strlen(value) + 1;
    copy = (char *)malloc(len);
    if (copy == NULL) {
        fprintf(stderr, "run out of memory.\n");
        exit(1);
    }
    memcpy(copy, value, len);
    return copy;
}

past newAstNode()
{
    past node = (past)malloc(sizeof(ast));
    if (node == NULL) {
        fprintf(stderr, "run out of memory.\n");
        exit(1);
    }
    memset(node, 0, sizeof(ast));
    return node;
}

past newNum(int value)
{
    past var = newAstNode();
    var->nodeType = "intValue";
    var->ivalue = value;
    return var;
}

past newExpr(int oper, past left, past right)
{
    past var = newAstNode();
    var->nodeType = "expr";
    var->ivalue = oper;
    var->left = left;
    var->right = right;
    var->strValue = "@";
    return var;
}

past newDoubleExpr(char *logic_oper, past left, past right)
{
    past var = newAstNode();
    var->nodeType = "expr";
    var->strValue = copy_string(logic_oper);
    var->left = left;
    var->right = right;
    return var;
}

past newBasicNode(char *nodeType, past left, past right, past next)
{
    past root = newAstNode();
    root->nodeType = copy_string(nodeType);
    root->left = left;
    root->right = right;
    root->next = next;
    return root;
}

past newNextNode(char *nodeType, past older, past younger)
{
    past root = NULL;

    if (older == NULL || strcmp(nodeType, older->nodeType) != 0) {
        root = newAstNode();
        root->nodeType = copy_string(nodeType);
        root->left = older;
        if (older != NULL) {
            older->next = younger;
        }
        root->ivalue = (older == NULL) ? 0 : 1;
    } else {
        past cursor;
        root = older;
        cursor = older->left;
        if (cursor == NULL) {
            root->left = younger;
        } else {
            while (cursor->next != NULL) {
                cursor = cursor->next;
            }
            cursor->next = younger;
        }
        root->ivalue++;
    }
    return root;
}

past newTypeNode(char *strVal)
{
    past root = newAstNode();
    root->nodeType = "type";
    root->strValue = copy_string(strVal);
    return root;
}

past newIDNode(char *strVal)
{
    past root = newAstNode();
    root->nodeType = "parameter";
    root->strValue = copy_string(strVal);
    return root;
}

void showAst(past node, int nest)
{
    int i;

    if (node == NULL) {
        return;
    }
    for (i = 0; i < nest; i++) {
        printf("  ");
    }
    if (node->nodeType != NULL && strcmp(node->nodeType, "expr") == 0) {
        if (node->strValue != NULL && strcmp(node->strValue, "@") == 0) {
            printf("%s '%c'\n", node->nodeType, (char)node->ivalue);
        } else {
            printf("%s %s\n", node->nodeType,
                   node->strValue == NULL ? "<null>" : node->strValue);
        }
    } else if (node->nodeType != NULL && strcmp(node->nodeType, "intValue") == 0) {
        printf("%s . %d\n", node->nodeType, node->ivalue);
    } else {
        if (node->strValue == NULL) {
            if (node->ivalue) {
                printf("%s . %d\n", node->nodeType, node->ivalue);
            } else {
                printf("%s .\n", node->nodeType);
            }
        } else if (node->ivalue) {
            printf("%s %s %d\n", node->nodeType, node->strValue, node->ivalue);
        } else {
            printf("%s %s .\n", node->nodeType, node->strValue);
        }
    }
    showAst(node->left, nest + 1);
    showAst(node->right, nest + 1);
    showAst(node->next, nest);
}
