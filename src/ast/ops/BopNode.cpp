
#include "BopNode.h"

BopNode::BopNode(char op, AstNode left, AstNode right) noexcept {
    this->op = op;
    this->left = left;
    this->right = right;
}
