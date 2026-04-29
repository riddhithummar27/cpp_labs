#include <iostream>
using namespace std;

class Book {
private:
    int id, copies;
    string title, author;

public:
    // Add book details
    void addBook() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Copies: ";
        cin >> copies;
    }

    // Issue book
    void issue() {
        if (copies > 0) {
            copies--;
            cout << "Book Issued\n";
        } else {
            cout << "Book Not Available\n";
        }
    }

    // Return book
    void returnBook() {
        int days;
        cout << "Enter late days: ";
        cin >> days;

        copies++;
        cout << "Book Returned\n";
        cout << "Fine: " << days * 2 << endl;
    }

    // Search book
    void search(string key) {
        if (title == key || author == key) {
            display();
        }
    }

    // Display book
    void display() {
        cout << id << " " << title << " " << author 
             << " Copies: " << copies << endl;
    }

    int getCopies() {
        return copies;
    }
};

int main() {
    Book b[5];
    int n = 0, choice;

    do {
        cout << "\n1.Add\n2.Issue\n3.Return\n4.Display\n5.Search\n6.Total\n0.Exit\n";
        cin >> choice;

        if (choice == 1) {
            b[n].addBook();
            n++;
        }

        else if (choice == 2) {
            int i;
            cout << "Enter index: ";
            cin >> i;
            b[i].issue();
        }

        else if (choice == 3) {
            int i;
            cout << "Enter index: ";
            cin >> i;
            b[i].returnBook();
        }

        else if (choice == 4) {
            for (int i = 0; i < n; i++) {
                b[i].display();
            }
        }

        else if (choice == 5) {
            string key;
            cout << "Enter title/author: ";
            cin >> key;
            for (int i = 0; i < n; i++) {
                b[i].search(key);
            }
        }

        else if (choice == 6) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                total += b[i].getCopies();
            }
            cout << "Total Copies: " << total << endl;
        }

    } while (choice != 0);

    return 0;
}
