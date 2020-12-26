
#ifndef PUPC_CHARNODE_H
#define PUPC_CHARNODE_H


#include "../AstNode.h"

struct CharNode: public AstNode {
    explicit CharNode(char value) noexcept;
};


#endif //PUPC_CHARNODE_H
