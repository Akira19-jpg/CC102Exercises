#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main() {
    ifstream inFile("WORDS.TXT");
    ofstream outFile("OUTPUT.TXT");
    set<string> words;
    string word;

    if (!inFile || !outFile) {
        cout << "Error opening file\n";
        return 1;
    }

    while (inFile >> word) {
        words.insert(word);
    }

    for (const auto& w : words) {
        outFile << w << " ";
    }

    inFile.close();
    outFile.close();

    cout << "Duplicates removed. Check OUTPUT.TXT\n";
    return 0;
}
