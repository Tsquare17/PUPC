#include <fstream>
#include <iostream>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <vector>
#include "lexer/Token.h"
#include "lexer/Lexer.h"
#include "parser/Parser.h"

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

    Parser::parse(lex);

    return 0;
}
