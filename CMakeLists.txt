cmake_minimum_required(VERSION 3.15)
project(PUPC)

set(CMAKE_CXX_STANDARD 20)

add_executable(pupc main.cpp Token.cpp Token.h Lexer.cpp Lexer.h)