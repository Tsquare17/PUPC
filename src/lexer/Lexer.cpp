#include "Lexer.h"

Token Lexer::next() {
    while(Token::is_space(current_char())) {
        get_next();
    }

    if(Token::is_char(current_char())) {
        return identifier();
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

    if(Token::is_eol(current_char())) {
        return eol();
    }

    if(Token::is_eof(current_char())) {
        return eof();
    }

    const char* begin = m_begin;
    get_next();
    return Token(Token::Type::Unknown, begin, 1);

}

Token Lexer::identifier() {
    const char* begin = m_begin;
    get_next();

    if(Token::is_slash(current_char())) {
        while(!Token::is_eol(current_char())) {
            get_next();
        }
        return Token(Token::Type::Comment, begin, m_begin);
    }

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

    return Token(Token::Type::Delimiter, begin, 1);
}

Token Lexer::eol() {
    const char* begin = m_begin;
    get_next();
    return Token(Token::Type::Eol, begin, 1);
}

Token Lexer::eof() {
    return Token(Token::Type::Eof, m_begin, 1);
}