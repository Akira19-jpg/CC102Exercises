#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

// 1. Create a struct named Book
struct Book {
    int barcode;
    string title;
    int year;
    int rating;

    // Helper to get the category string based on rating
    string getCategory() const {
        switch (rating) {
            case 5: return "Excellent";
            case 4: return "Very Good";
            case 3: return "Good";
            case 2: return "Fair";
            case 1: return "Poor";
            case 0: return "No Rating";
            default: return "Invalid";
        }
    }
};

// Function to check if barcode is unique
bool isBarcodeUnique(const vector<Book>& books, int code) {
    for (const auto& b : books) {
        if (b.barcode == code)
            return false;
    }
    return true;
}

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\n--- Book Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Edit Book\n";
        cout << "3. Delete Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // ================= ADD BOOK =================
        if (choice == 1) {
            Book temp;

            cout << "Enter Barcode: ";
            cin >> temp.barcode;

            // Barcode must be unique
            if (!isBarcodeUnique(library, temp.barcode)) {
                cout << "Error: Barcode already exists. Please enter a unique code.\n";
            } else {
                cin.ignore();

                cout << "Enter Title: ";
                getline(cin, temp.title);

                cout << "Enter Year Published: ";
                cin >> temp.year;

                cout << "Enter Rating (0-5): ";
                cin >> temp.rating;

                if (temp.rating < 0 || temp.rating > 5)
                    temp.rating = 0;

                library.push_back(temp);
                cout << "Book added successfully!\n";
            }
        }

        // ================= EDIT BOOK =================
        else if (choice == 2) {
            int code;
            cout << "Enter Barcode of book to edit: ";
            cin >> code;

            bool found = false;

            for (auto& b : library) {
                if (b.barcode == code) {
                    cout << "Editing: " << b.title << endl;

                    cin.ignore();
                    cout << "Enter New Title: ";
                    getline(cin, b.title);

                    cout << "Enter New Year: ";
                    cin >> b.year;

                    cout << "Enter New Rating: ";
                    cin >> b.rating;

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found.\n";
        }

        // ================= DELETE BOOK =================
        else if (choice == 3) {
            int code;
            cout << "Enter Barcode to delete: ";
            cin >> code;

            auto it = remove_if(library.begin(), library.end(),
                                [code](Book b) {
                                    return b.barcode == code;
                                });

            if (it != library.end()) {
                library.erase(it, library.end());
                cout << "Book deleted.\n";
            } else {
                cout << "Book not found.\n";
            }
        }

        // ================= DISPLAY BOOKS =================
        else if (choice == 4) {
            if (library.empty()) {
                cout << "No books in the system.\n";
            } else {
                cout << "\n"
                     << left << setw(10) << "Barcode"
                     << setw(20) << "Title"
                     << setw(10) << "Year"
                     << setw(10) << "Rating"
                     << "Category" << endl;

                cout << string(60, '-') << endl;

                for (const auto& b : library) {
                    cout << left << setw(10) << b.barcode
                         << setw(20) << b.title
                         << setw(10) << b.year
                         << setw(10) << b.rating
                         << b.getCategory() << endl;
                }
            }
        }

    } while (choice != 5);

    cout << "Exiting program. Goodbye!\n";
    return 0;
}
