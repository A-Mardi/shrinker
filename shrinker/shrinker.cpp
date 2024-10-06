// shrinker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "input_handler.h"
#include "rle_compressor.h"
#include "rle_decompressor.h"
#include <iostream>
#include <fstream>
#include <string>

void compressRLE(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    char currentChar;
    char previousChar = '\0';
    int count = 0;

    while (inputFile.get(currentChar)) {
        if (currentChar == previousChar) {
            count++;
        }
        else {
            if (count > 0) {
                outputFile << count + 1 << previousChar;
            }
            count = 0;
            previousChar = currentChar;
            count++;
        }
    }

    if (count > 0) {
        outputFile << count << previousChar;
    }

    inputFile.close();
    outputFile.close();
}

void decompressRLE(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    int count;
    char character;

    while (inputFile >> count >> character) {
        for (int i = 0; i < count; ++i) {
            outputFile << character;
        }
    }

    inputFile.close();
    outputFile.close();
}


int main(int argc, char* argv[]) {

    std::string rleInputFilePath;
    std::string rleCompressedFilePath;
    std::string rleDecompressedFilePath;

    std::cout << "RLE Compression:" << std::endl;
    handleInput(argc, argv, rleInputFilePath, rleCompressedFilePath, rleDecompressedFilePath);
    compressRLE(rleInputFilePath, rleCompressedFilePath);
    decompressRLE(rleCompressedFilePath, rleDecompressedFilePath);
}
