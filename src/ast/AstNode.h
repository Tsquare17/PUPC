
#ifndef PUPC_ASTNODE_H
#define PUPC_ASTNODE_H


#include <string>

struct AstNode {
    char op;
    AstNode *left;
    AstNode *right;
    std::string data;
    std::string type;

    std::string getValue();
};


#endif //PUPC_ASTNODE_H
