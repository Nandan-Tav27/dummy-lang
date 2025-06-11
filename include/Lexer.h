#pragma once

#include "Token.h"

class Lexer {
    std::string data;

public:
    explicit Lexer(std::string input) : data(std::move(input)) {}
    [[ nodiscard ]] std::vector<Token> lex();
};