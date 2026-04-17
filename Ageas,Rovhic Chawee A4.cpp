#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // 1. Define the data and filenames
    std::vector<std::string> colors = {"Crimson", "Emerald", "Cobalt", "Amber", "Violet"};
    std::string sourceFile = "color.txt";
    std::string destinationFile = "color_copy.txt";

    // --- PHASE 1: WRITING TO COLOR.TXT ---
    std::ofstream outFile(sourceFile);

    if (!outFile) {
        std::cerr << "Error: Could not create " << sourceFile << std::endl;
        return 1;
    }

    for (const auto& color : colors) {
        outFile << color << "\n";
    }

    outFile.close();
    std::cout << "Successfully created " << sourceFile << ".\n";


    // --- PHASE 2: READING AND COPYING TO COLOR_COPY.TXT ---
    std::ifstream inFile(sourceFile);
    std::ofstream copyFile(destinationFile);

    // Validation: Ensure both files opened correctly
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open " << sourceFile << " for reading." << std::endl;
        return 1;
    }
    if (!copyFile.is_open()) {
        std::cerr << "Error: Could not create " << destinationFile << std::endl;
        return 1;
    }

    std::string line;
    // Read the source file line by line and write to the copy
    while (std::getline(inFile, line)) {
        copyFile << line << "\n";
    }

    // --- PHASE 3: CLEANUP ---
    inFile.close();
    copyFile.close();

    std::cout << "Successfully copied content to " << destinationFile << ".\n";

    return 0;
}


