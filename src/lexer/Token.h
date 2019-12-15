#ifndef PUPC_TOKEN_H
#define PUPC_TOKEN_H


#include <string>

class Token {
public:
    enum class Type {
        Identifier,
        Operator,
        Number,
        Delimiter,
        Unknown,
        Eof,
    };

    Token(Type type, const char* begin, const char* end) : m_type{type}, m_lex(begin, std::distance(begin, end)) {}

    Token(Type type, const char* begin, std::size_t len) : m_type{type}, m_lex(begin, len) {}

    Type m_type{};
    std::string_view m_lex{};

    [[nodiscard]] Type type() const {
        return m_type;
    }

    [[nodiscard]] std::string_view lex() const {
        return m_lex;
    }

    [[nodiscard]] bool is(Type type) const;

    static bool is_nothing(char c);
    static bool is_char(char c);
    static bool is_operator(char c);
    static bool is_number(char c);
    static bool is_delimiter(char c);
    static bool is_eof(char c);
};


#endif //PUPC_TOKEN_H
