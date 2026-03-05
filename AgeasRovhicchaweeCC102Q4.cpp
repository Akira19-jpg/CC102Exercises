#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int ROWS = 5;
    const int COLS = 10;
    int computers[ROWS][COLS] = {0};
    int choice;

    do {
        cout << "\n===== COMPUTER SHOP RENTAL SYSTEM =====\n";
        cout << "1. View Computer Layout\n";
        cout << "2. Rent a Computer\n";
        cout << "3. Return a Computer\n";
        cout << "4. Reset Rental System\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n   ";
            for (int c = 0; c < COLS; c++)
                cout << setw(3) << c + 1;
            cout << endl;

            char rowLabel = 'A';
            for (int r = 0; r < ROWS; r++) {
                cout << rowLabel++ << " ";
                for (int c = 0; c < COLS; c++) {
                    cout << setw(3) << computers[r][c];
                }
                cout << endl;
            }
        }

        else if (choice == 2) {
            int row, col, hours;
            bool full = true;

            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (computers[r][c] == 0)
                        full = false;
                }
            }

            if (full) {
                cout << "Shop is fully occupied.\n";
                continue;
            }

            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;
            cout << "Enter hours: ";
            cin >> hours;

            if (row < 1 || row > 5 || col < 1 || col > 10 || hours <= 0) {
                cout << "Invalid input.\n";
                continue;
            }

            if (computers[row-1][col-1] > 0) {
                cout << "Computer unit already rented!\n";
            } else {
                computers[row-1][col-1] = hours;
                char rLabel = 'A' + (row - 1);
                cout << "Computer unit " << rLabel << col
                     << " successfully rented for " << hours << " hour(s)!\n";
            }
        }

        else if (choice == 3) {
            int row, col;

            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;

            if (row < 1 || row > 5 || col < 1 || col > 10) {
                cout << "Invalid input.\n";
                continue;
            }

            if (computers[row-1][col-1] == 0) {
                cout << "Computer unit is already available!\n";
            } else {
                int hours = computers[row-1][col-1];
                double sale = hours * 20.00;

                char rLabel = 'A' + (row - 1);

                cout << "Computer unit " << rLabel << col << " has been returned.\n";
                cout << fixed << setprecision(2);
                cout << "Rental Sale: P" << sale << endl;

                computers[row-1][col-1] = 0;
            }
        }

        else if (choice == 4) {
            for (int r = 0; r < ROWS; r++)
                for (int c = 0; c < COLS; c++)
                    computers[r][c] = 0;

            cout << "Rental system reset successfully!\n";
        }

        else if (choice == 5) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
