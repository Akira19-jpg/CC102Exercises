#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main (){
    char choice;
    do {
        int s, d;

        cout <<"Enter number of students: ";
        cin >> s;
        cout <<"Enter number of days: ";
        cin >> d;

        vector<vector<int>> a(s, vector<int>(d));

        for (int i = 0; i < s; i++) {
            cout << "\nStudent "  <<   i + 1  << " attendance: ";
        for (int j = 0; j < d; j++) {
            cin >> a[i][j];

        }
    }


        cout <<"\n" <<"Students";
        for (int i = 0; i < d; i++) {
            cout << setw(5) << (" D"   + to_string ( i + 1));
        }


        cout << setw(10)  << "Total";
        cout << setw(13)  << "Percentage";
        cout << setw(10)  << "Remarks" << endl;

        cout << "-----------------------------------------------------------------\n";

        for (int i = 0; i < s; i++){
            int total = 0;

            cout << setw(5) << i + 1;

        for (int j = 0; j < d; j++) {
            cout << setw(6) << a[i][j];
            total += a[i][j];
        }
         double percentage = total * 100.0 / d;
         cout << setw(8) << total;
         cout << setw (11) << percentage << "%";
         cout << setw (10) << (percentage < 50 ?  "DRP" : "OK") << endl;}

    cout<<"\nWould you like to run the program? (y/n): ";
    cin >> choice;

  } while (choice =='y' || choice == 'Y');

    cout <<"\nProgram terminated.\n";

 return 0;
}
