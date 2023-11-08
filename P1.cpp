
#include <iostream>
#include <fstream>
#include "scanner.h"

int main(int argc, char* argv[]) {
    std::ifstream inputFile;

    if (argc > 2)
    {
        // error if user attempts to input multiple files
        std::cerr << "Error: Please only input one File.\n";
        return 1;
    }

    else if (argc == 2)
    {
        inputFile.open(argv[1]);

        if (!inputFile.is_open())
        {
            // error if file is unable to be opened
            std::cerr << "Error: Could not open File: " << argv[1] << std::endl;
            return 1;
        }

        scanner(inputFile);
        inputFile.close();  // closes file after it is done being utitlized
    }

    return 0;
}
