#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("TEXT.TXT");
    char ch;
    int upper = 0, lower = 0;

    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    while (file.get(ch)) {
        if (isupper(ch)) upper++;
        else if (islower(ch)) lower++;
    }

    file.close();

    cout << "Uppercase letters: " << upper << endl;
    cout << "Lowercase letters: " << lower << endl;

    return 0;
}
