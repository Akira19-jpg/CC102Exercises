#include <iostream>
#include <fstream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Function to count prime numbers in file
int countPrimesInFile(const string& filename) {
    ifstream file(filename);
    int num, count = 0;

    if (!file) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    while (file >> num) {
        if (isPrime(num)) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    string filename = "NUMS.TXT";

    int primeCount = countPrimesInFile(filename);

    if (primeCount != -1) {
        cout << "Number of prime numbers: " << primeCount << endl;
    }

    return 0;
}
