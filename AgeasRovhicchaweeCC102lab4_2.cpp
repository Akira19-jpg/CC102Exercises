#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        double sales[5][4] = {0};
        char cont;

        
        do {
            int salesperson, product;
            double amount;

            cout << "\nSalesperson (1-4): ";
            cin >> salesperson;

            cout << "Product (1-5): ";
            cin >> product;

            cout << "Amount sold: ";
            cin >> amount;

            
            sales[product - 1][salesperson - 1] += amount;

            cout << "Enter another record? (Y/N): ";
            cin >> cont;

        } while (cont == 'Y' || cont == 'y');

        
        cout << "\nProduct\t";
        for (int sp = 0; sp < 4; sp++) {
            cout << "SP" << sp + 1 << "\t";
        }
        cout << "Total\n";

        double grandTotal = 0;

        
        for (int p = 0; p < 5; p++) {
            double rowTotal = 0;
            cout << p + 1 << "\t";

            for (int sp = 0; sp < 4; sp++) {
                cout << fixed << setprecision(2) << sales[p][sp] << "\t";
                rowTotal += sales[p][sp];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        
        cout << "Total\t";
        for (int sp = 0; sp < 4; sp++) {
            double colTotal = 0;

            for (int p = 0; p < 5; p++) {
                colTotal += sales[p][sp];
            }

            cout << fixed << setprecision(2) << colTotal << "\t";
        }

        cout << grandTotal << endl;

        cout << "\nRun program again? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    return 0;
}