cmake_minimum_required(VERSION 3.15)
project(PUPC)

set(CMAKE_CXX_STANDARD 20)

add_executable(pupc src/main.cpp src/lexer/Token.cpp src/lexer/Token.h src/lexer/Lexer.cpp src/lexer/Lexer.h src/ast/Ast.cpp src/ast/Ast.h src/ast/ops/Bop.cpp src/ast/ops/Bop.h src/parser/Parser.cpp src/parser/Parser.h src/ast/ops/Uop.cpp src/ast/ops/Uop.h)