#include "Lexer.h"

Token Lexer::next() {
    while(Token::is_nothing(current_char())) {
        get_next();
    }

    if(Token::is_char(current_char())) {
        return keyword();
    }

    if(Token::is_operator(current_char())) {
        return operator_type();
    }

    if(Token::is_number(current_char())) {
        return number();
    }

    if(Token::is_delimiter(current_char())) {
        return delimiter();
    }

    return Token(Token::Type::End, m_begin, 1);
}

Token Lexer::keyword() {
    const char* begin = m_begin;
    get_next();
    while(Token::is_char(current_char())) {
        get_next();
    }

    return Token(Token::Type::Identifier, begin, m_begin);
}

Token Lexer::operator_type() {
    const char* begin = m_begin;
    get_next();
    while(Token::is_operator(current_char())) {
        get_next();
    }

    return Token(Token::Type::Operator, begin, m_begin);
}

Token Lexer::number() {
    const char* begin = m_begin;
    get_next();
    while(Token::is_number(current_char())) {
        get_next();
    }

    return Token(Token::Type::Number, begin, m_begin);
}

Token Lexer::delimiter() {
    const char* begin = m_begin;
    get_next();
    while(Token::is_delimiter(current_char())) {
        get_next();
    }

    return Token(Token::Type::Delimiter, begin, m_begin);
}
