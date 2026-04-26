#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("TEXT.TXT");
    char ch;
    int freq[256] = {0};

    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    while (file.get(ch)) {
        freq[(unsigned char)ch]++;
    }

    file.close();

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << " : " << freq[i] << endl;
        }
    }

    return 0;
}
