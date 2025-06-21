#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"
#include "Token.h"

std::string readFileIntoString(const std::string& filePath) {
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

    try {
        // Tokenize
        Lexer lexer(program);
        while (lexer.hasNextToken()) {
            std::cout << lexer.getNextToken().type << "\n";
        }

        // Parse

    } catch (const std::exception& e) {
        std::cerr << "Error while compiling: " << e.what() << "\n";
        return 1;
    }

    // SEMA
    // ...

    return 0;
}