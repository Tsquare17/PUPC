cmake_minimum_required(VERSION 3.15)
project(PUPC)

set(CMAKE_CXX_STANDARD 20)

set(PUPC_HEADERS
        src/lexer/Token.h
        src/lexer/Lexer.h
        src/parser/Parser.h
        src/ast/ExpressionNode.h
        src/ast/vals/IntNode.h
        src/ast/AstNode.h
        src/ast/ops/BopNode.h
        src/ast/vals/CharNode.h)

set(PUPC_SOURCE
        src/main.cpp
        src/lexer/Token.cpp
        src/lexer/Lexer.cpp
        src/parser/Parser.cpp
        src/ast/ExpressionNode.cpp
        src/ast/vals/IntNode.cpp
        src/ast/AstNode.cpp
        src/ast/ops/BopNode.cpp
        src/ast/vals/CharNode.cpp)

add_executable(pupc ${PUPC_SOURCE} ${PUPC_HEADERS})