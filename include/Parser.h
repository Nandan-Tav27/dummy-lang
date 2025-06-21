#pragma once

#include "Lexer.h"

class Parser {
    Lexer& lexer;

public:
    explicit Parser(Lexer& lexer): lexer(lexer) {}
    // For now we will just return a bool representing
    // whether the input is syntactically valid or not
    bool parse();

private:
    bool assignment();
    bool expression();
    void statement();
};