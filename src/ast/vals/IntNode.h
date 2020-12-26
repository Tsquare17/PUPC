
#ifndef PUPC_INTNODE_H
#define PUPC_INTNODE_H


#include "../AstNode.h"

struct IntNode : public AstNode {
public:
    explicit IntNode(int value) noexcept;
};


#endif //PUPC_INTNODE_H
