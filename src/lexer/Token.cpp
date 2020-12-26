#include "Token.h"

bool Token::is_space(char c) {
    return c == ' ';
}

bool Token::is_operator(char c) {
    switch(c) {
        case '=':
        case '+':
        case '-':
            return true;
        default:
            return false;
    }
}

bool Token::is_number(char c) {
    return isdigit(static_cast<char>(c));
}

bool Token::is_char(char c) {
    return isalpha(c) || Token::is_slash(c);
}

bool Token::is_slash(char c) {
    return c == '/';
}

bool Token::is_delimiter(char c) {
    return c == ';';
}

bool Token::is_eol(char c) {
    return c == '\n';
}

bool Token::is_eof(char c) {
    return c == '\0';
}

bool Token::is(Token::Type type) const {
    return m_type == type;
}
