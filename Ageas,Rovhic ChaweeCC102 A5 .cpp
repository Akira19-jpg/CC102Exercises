#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    std::vector<std::string> numbers = {"One", "Two", "Three", "Four", "Five", "Six"};
    std::string originalFile = "original.txt";
    std::string sortedFile = "sorted.txt";


    std::ofstream outOriginal(originalFile);
    if (!outOriginal) {
        std::cerr << "Error: Could not create " << originalFile << std::endl;
        return 1;
    }

    for (const auto& num : numbers) {
        outOriginal << num << "\n";
    }
    outOriginal.close();
    std::cout << "Created original.txt successfully.\n";


    std::ifstream inOriginal(originalFile);
    if (!inOriginal) {
        std::cerr << "Error: Could not open " << originalFile << " for reading." << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::string temp;
    while (std::getline(inOriginal, temp)) {
        if (!temp.empty()) {
            lines.push_back(temp);
        }
    }
    inOriginal.close();


    std::sort(lines.begin(), lines.end());


    std::ofstream outSorted(sortedFile);
    if (!outSorted) {
        std::cerr << "Error: Could not create " << sortedFile << std::endl;
        return 1;
    }

    for (const auto& sortedNum : lines) {
        outSorted << sortedNum << "\n";
    }
    outSorted.close();

    std::cout << "Created sorted.txt successfully (Alphabetical order).\n";

    return 0;
}
