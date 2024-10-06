#include <iostream>
#include "input_handler.h"

void handleInput(int argc, char* argv[], std::string& inputFilePath, std::string& compressedFilePath, std::string& decompressedFilePath) {
    if (argc == 4) {
        // Use command-line arguments if provided
        inputFilePath = argv[1];
        compressedFilePath = argv[2];
        decompressedFilePath = argv[3];
    }
    else {
        // Prompt for input if no command-line arguments
        std::cout << "Enter the path of the input file: ";
        std::getline(std::cin, inputFilePath);

        std::cout << "Enter the path for the compressed output file: ";
        std::getline(std::cin, compressedFilePath);

        std::cout << "Enter the path for the decompressed output file: ";
        std::getline(std::cin, decompressedFilePath);
    }
}
