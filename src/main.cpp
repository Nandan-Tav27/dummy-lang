#include <iostream>
#include <fstream>

int readFileIntoString(std::ifstream &ifs, std::string &str) {

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
    const std::fstream file(argv[2], std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << argv[2] << "\n";
        return 1;
    }

    std::string_view buffer;

    // Tokenize
    // Parse
    // SEMA
    // ...

    return 0;
}