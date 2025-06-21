#pragma once

#include "Token.h"

class Lexer {
    std::string data;
    size_t pos = 0;

public:
    explicit Lexer(std::string input) : data(std::move(input)) {}
    [[nodiscard]] Token getNextToken();
    bool hasNextToken() const;
};