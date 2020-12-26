
#include <iostream>
#include <vector>
#include <map>
#include "ExpressionNode.h"
#include "vals/IntNode.h"
#include "vals/CharNode.h"


ExpressionNode::ExpressionNode(char op, int left, int right) {
    this->op = op;

    this->left = IntNode(left);
    this->right = IntNode(right);
}

ExpressionNode::ExpressionNode(char op, AstNode left, AstNode right) {

    if(ExpressionNode::hasGreaterPrecedence(op, left.op)) {
        std::cout << "has greater precedence than left\n";
    }

    if(ExpressionNode::hasGreaterPrecedence(op, right.op)) {
        std::cout << "has greater precedence than right\n";
    }

    this->left = left;
    this->right = right;
    this->op = op;
}

//ExpressionNode::ExpressionNode()

void ExpressionNode::addNode(struct AstNode leaf, ExpressionNode tree) {
    // TODO: add leaf to tree
}

bool ExpressionNode::hasGreaterPrecedence(char op1, char op2) {
    std::map<char, int> precedence;
    precedence['+'] = 20;
    precedence['-'] = 20;
    precedence['*'] = 40;
    precedence['/'] = 40;

    return precedence[op1] > precedence[op2];
}

ExpressionNode::ExpressionNode(char op, int left, ExpressionNode right) {

    bool greater = hasGreaterPrecedence(op, right.op);
    if(hasGreaterPrecedence(op, right.op)) {
        std::cout << "has greater precedence than right\n";
    }

    this->op = op;
    addNode( IntNode(left), right);
}
