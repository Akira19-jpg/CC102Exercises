#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[100][100]; 
        double average[100];

        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " scores:\n";

            double sum = 0;

            for (int j = 0; j < quizzes; j++) {
                cout << "Quiz " << j + 1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = sum / quizzes;
        }

        
        cout << "\nStudent\t";
        for (int j = 0; j < quizzes; j++) {
            cout << "Q" << j + 1 << "\t";
        }
        cout << "Average\n";

        for (int i = 0; i < students; i++) {
            cout << i + 1 << "\t";

            for (int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << "\t";
            }

            cout << fixed << setprecision(2) << average[i] << endl;
        }

        cout << "\nRun program again? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    return 0;
}