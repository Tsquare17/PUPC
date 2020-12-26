
#ifndef PUPC_BOPNODE_H
#define PUPC_BOPNODE_H


#include "../AstNode.h"

struct BopNode: public AstNode {
    char op;
    AstNode left;
    AstNode right;
    BopNode(char op, AstNode left, AstNode right) noexcept;
};


#endif //PUPC_BOPNODE_H
