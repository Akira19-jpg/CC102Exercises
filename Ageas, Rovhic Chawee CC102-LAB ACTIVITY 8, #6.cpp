#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isPalindrome(string word) {
    int start = 0, end = word.length() - 1;

    while (start < end) {
        if (word[start] != word[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int countPalindromes(const string& filename) {
    ifstream file(filename);
    string word;
    int count = 0;

    if (!file) {
        cout << "Error opening file\n";
        return -1;
    }

    while (file >> word) {
        if (isPalindrome(word)) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    cout << "Palindrome words: "
         << countPalindromes("WORDS.TXT") << endl;
    return 0;
}
