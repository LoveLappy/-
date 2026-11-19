#ifndef GENLLVM_H
#define GENLLVM_H

#include "ast.h"

enum { T_INT = 1 };

int genExpr(past node);

int genArithmeticExpr(past node, char *result);
int genLogicExpr(past node, char *result);
int genAssignStmt(past node, char *result);
int genIfStmt(past node, char *result);
int genWhileStmt(past node, char *result);

#endif
