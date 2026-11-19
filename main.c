#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "genllvm.h"

extern int yyparse(void);
extern FILE *yyin;
past astRoot;

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv)
{
    const char *input_name = "./test.c";
    int parse_result;

    if (argc > 2) {
        fprintf(stderr, "usage: %s [source-file]\n", argv[0]);
        return 1;
    }
    if (argc == 2) {
        input_name = argv[1];
    }

    yyin = fopen(input_name, "r");
    if (yyin == NULL) {
        fprintf(stderr, "cannot open %s\n", input_name);
        return 1;
    }

    parse_result = yyparse();
    fclose(yyin);
    if (parse_result != 0 || astRoot == NULL) {
        return 1;
    }

    if (genExpr(astRoot) != 0) {
        return 1;
    }
    return 0;
}
