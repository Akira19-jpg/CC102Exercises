#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countLinesNotStartingWithA(const string& filename) {
    ifstream file(filename);
    string line;
    int count = 0;

    if (!file) {
        cout << "Error opening file\n";
        return -1;
    }

    while (getline(file, line)) {
        if (!line.empty() && line[0] != 'A') {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    cout << "Lines not starting with A: "
         << countLinesNotStartingWithA("STORY.TXT") << endl;
    return 0;
}
