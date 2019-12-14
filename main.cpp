#include <fstream>
#include <iostream>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include "Token.h"
#include "Lexer.h"

namespace bi = boost::interprocess;

int main(int argc, char **argv)
{
    char* file = argv[1];

    std::ifstream f(file);

    if(!f.good()) {
        std::cout << "File not found\n";
        return 1;
    }

    bi::file_mapping mapping(file, bi::read_only);
    bi::mapped_region region(mapping, bi::read_only);

    char const* const mmap = static_cast<char*>(region.get_address());

    Lexer lex(mmap);
    for(auto token = lex.next(); !token.is(Token::Type::End); token = lex.next()) {
        if(token.type() == Token::Type::Identifier) {
            std::cout << "Identifier: ";
        }
        if(token.type() == Token::Type::Operator) {
            std::cout << "Operator: ";
        }
        if(token.type() == Token::Type::Number) {
            std::cout << "Number: ";
        }
        if(token.type() == Token::Type::Delimiter) {
            std::cout << "Delimiter: ";
        }

        std::cout << token.lex() << "\n";
    }

    return 0;
}
