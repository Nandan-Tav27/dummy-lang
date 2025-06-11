#pragma once

#include <optional>
#include <string>

enum TokenType {
    identifier,
    number,
    assignment_operator,
    addition_operator,
    subtraction_operator,
    multiplication_operator,
    division_operator,
    left_parenthesis,
    right_parenthesis,
    semicolon
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};
