%{

#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "lrparser.tab.h"

%}

INTEGER     [0-9]+
OCTALCONS   0[0-7]+
HEXCONS     0[xX][0-9a-fA-F]+
IDENTIFIER  [_a-zA-Z][_a-zA-Z0-9]*

%%
[ \t\r\n]+                  { /* skip whitespace */ }
"//"[^\n]*                  { /* skip single-line comment */ }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* skip block comment */ }

"("                         { return '('; }
")"                         { return ')'; }
"{"                         { return '{'; }
"}"                         { return '}'; }
"["                         { return '['; }
"]"                         { return ']'; }
","                         { return ','; }
";"                         { return ';'; }
"+"                         { return '+'; }
"-"                         { return '-'; }
"*"                         { return '*'; }
"/"                         { return '/'; }
"%"                         { return '%'; }
"<="                        { return LESSEQ; }
">="                        { return GREATEQ; }
"=="                        { return EQ; }
"!="                        { return NOTEQ; }
"&&"                        { return AND; }
"||"                        { return OR; }
"<"                         { return '<'; }
">"                         { return '>'; }
"!"                         { return '!'; }
"="                         { return '='; }

"int"                       { return INT; }
"void"                      { return VOID; }
"const"                     { return CONST; }
"if"                        { return IF; }
"else"                      { return ELSE; }
"while"                     { return WHILE; }
"break"                     { return BREAK; }
"continue"                  { return CONTINUE; }
"return"                    { return RETURN; }

{HEXCONS}                   { yylval.number = (int)strtol(yytext, NULL, 0); return NUMBER; }
{OCTALCONS}                 { yylval.number = (int)strtol(yytext, NULL, 0); return NUMBER; }
{INTEGER}                   { yylval.number = atoi(yytext); return NUMBER; }

{IDENTIFIER}                { strncpy(yylval.strValue, yytext, sizeof(yylval.strValue) - 1); yylval.strValue[sizeof(yylval.strValue) - 1] = '\0'; return ID; }

%%

int yywrap(void)
{
    return 1;
}
