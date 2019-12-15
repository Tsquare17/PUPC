#include <vector>
#include <iostream>
#include "Parser.h"

void Parser::parse(Lexer lex) {
    std::vector< std::vector< Token > > statements = {};
    std::vector <Token> current_statement = {};
    for(auto token = lex.next(); !token.is(Token::Type::Eof); token = lex.next()) {

        if(token.type() != Token::Type::Delimiter) {
            // collect token
            current_statement.push_back(token);
        }

        if(token.type() == Token::Type::Delimiter) {
            // end the statement, and start another.
            statements.push_back(current_statement);
            current_statement = {};
            std::cout << "Delimiter: ";
        }

        if(token.type() == Token::Type::Identifier) {
            std::cout << "Identifier: ";
        }

        if(token.type() == Token::Type::Operator) {
            std::cout << "Operator: ";
        }

        if(token.type() == Token::Type::Number) {
            std::cout << "Number: ";
        }

        if(token.type() == Token::Type::Unknown) {
            std::cout << "Unknown : ";
        }

        std::cout << token.lex() << "\n";
    }

}