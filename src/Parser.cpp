#include "Parser.h"

#include <string>

// void reportError(const std::string& exception) {
//     throw std::runtime_error(exception);
// }
//
// bool Parser::parse() {
//
// }
//
// bool Parser::assignment() {
//
// }
//
// bool Parser::expression() {
//
// }
//
//
// void Parser::statement() {
//     // Get next token
//     // If it's an identifier then check for assignment
//     // otherwise check for expression
//     if (!lexer.hasNextToken())
//         reportError("No tokens received from Lexer");
//
//     Token token = lexer.getNextToken();
//     if (token.type == identifier) {
//         if (lexer.hasNextToken() && lexer.getNextToken().type == assignment_operator)
//         Token nextToken = lexer.getNextToken();
//     }
//    if (token.type == identifier) {
//        // If next token is assignment operator
//        // call assignment()
//        // else it's an expression
//    }
//     if (assignment()) {
//
//     } else if (expression()) {
//
//     } else {
//         reportError();
//     }
// }
//
