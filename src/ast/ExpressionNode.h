
#ifndef PUPC_EXPRESSIONNODE_H
#define PUPC_EXPRESSIONNODE_H


#include <string_view>
#include "AstNode.h"
#include "vals/IntNode.h"

class ExpressionNode {
public:
    char op;
    AstNode left;
    AstNode right;

    ExpressionNode(char op, int left, ExpressionNode right);
    ExpressionNode(char op, AstNode left, AstNode right);
    ExpressionNode(char op, int left, int right);
    void addNode(AstNode leaf, ExpressionNode tree);
    bool hasGreaterPrecedence(char op1, char op2);
};


#endif //PUPC_EXPRESSIONNODE_H
