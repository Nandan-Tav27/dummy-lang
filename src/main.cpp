#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"

std::string readFileIntoString(std::string filePath) {
    if (std::ifstream file(filePath); file.is_open()) {
        std::stringstream buff;
        buff << file.rdbuf();
        return buff.str();
    }
    throw std::runtime_error("Could not open file " + filePath);
}

int main(int argc, char *argv[]) {
    // Get input
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " compile <filename>\n";
        return 1;
    }

    if (std::strcmp(argv[1], "compile") != 0) {
        std::cerr << "Only compile functionality is supported!\nUsage: " << argv[0] << " compile <filename>\n";
        return 1;
    }

   // TODO: Ensure file extension is .toy

    std::string program;
    try {
        program = readFileIntoString(argv[2]);
    } catch (const std::exception& e) {
        std::cerr << "Error occurred while reading file: " << e.what() << "\n";
        return 1;
    }

    // Tokenize
    Lexer lexer(program);
    lexer.lex();
    // Parse
    // SEMA
    // ...

    return 0;
}