#include <vector>
#include <iostream>

#include "Token.h"
#include "Lexer.h"

Token Lexer::getNextToken() {
    if (pos >= data.length())
        return {end_of_file};


    while (pos < data.length()) {
        if (std::isspace(data.at(pos))) {
            pos++;
            continue;
        }

        // Handle comments
        if (data.at(pos) == '#') {
            while (pos < data.length() && data.at(pos) != '\n')
                pos++;
            continue;
        }

        // identifier
        if (std::isalpha(data.at(pos))) {
            Token token;
            token.type = identifier;
            token.value.emplace();
            token.value->push_back(data.at(pos));
            while (pos + 1 < data.length() && std::isalnum(data.at(pos + 1))) {
                pos++;
                token.value->push_back(data.at(pos));
            }
            pos++;
            return token;
        }

        // number
        if (std::isdigit(data.at(pos))) {
            Token token;
            token.type = number;
            token.value.emplace();
            token.value->push_back(data.at(pos));
            while (pos + 1 < data.length() && std::isdigit(data.at(pos + 1))) {
                pos++;
                token.value->push_back(data.at(pos));
            }
            pos++;
            return token;
        }

        // assignment_operator,
        if (data.at(pos) == '=') {
            pos++;
            return {assignment_operator};
        }

        // addition_operator,
        if (data.at(pos) == '+') {
            pos++;
            return {addition_operator};
        }

        // subtraction_operator,
        if (data.at(pos) == '-') {
            pos++;
            return {subtraction_operator};
        }

        // multiplication_operator,
        if (data.at(pos) == '*') {
            pos++;
            return {multiplication_operator};
        }

        // division_operator,
        if (data.at(pos) == '/') {
            pos++;
            return {division_operator};
        }

        // left_parenthesis,
        if (data.at(pos) == '(') {
            pos++;
            return {left_parenthesis};
        }

        // right_parenthesis,
        if (data.at(pos) == ')') {
            pos++;
            return {right_parenthesis};
        }

        // semicolon
        if (data.at(pos) == ';') {
            pos++;
            return {semicolon};
        }

        throw std::runtime_error("Encountered unexpected character '" + std::string(1, data.at(pos)) + "'");
    }
    return {end_of_file};
}

bool Lexer::hasNextToken() const {
    return pos < data.length();
}
