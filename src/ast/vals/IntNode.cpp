
#include <string>
#include "IntNode.h"

IntNode::IntNode(int value) noexcept : AstNode() {
    this->type = "int";
    this->data = std::to_string(value);
}

