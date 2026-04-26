#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("WORDS.TXT");
    string word, longest = "";

    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    while (file >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }

    file.close();

    cout << "Longest word: " << longest << endl;
    return 0;
}
