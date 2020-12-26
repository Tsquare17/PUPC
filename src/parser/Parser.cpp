#include <iostream>
#include <vector>
#include "Parser.h"
#include "../ast/ExpressionNode.h"

void Parser::parse(Lexer lex) {
    std::vector<std::string_view> statements;
    std::string statement;
    for(auto token = lex.next(); !token.is(Token::Type::Eof); token = lex.next()) {

        if(token.type() == Token::Type::Number) {
            while(token.type() != Token::Type::Delimiter && token.type() != Token::Type::Eof) {
                statements.push_back(token.lex());
                std::string current = token.lex().data();
                statement += " " + current;
                token = lex.next();
            }
        }

        if(token.type() == Token::Type::Comment) {
            std::cout << "Comment: ";
        }

        if(token.type() == Token::Type::Delimiter) {
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

        if(token.type() != Token::Type::Eol) {
            std::cout << token.lex() << "\n";
        }
    }

    /**
     * Test assembling AST.
     */
    ExpressionNode node = ExpressionNode('+', 1, 1);
    ExpressionNode node1 = ExpressionNode('-', 2, node);
}


