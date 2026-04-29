#include <iostream>
#include <vector>
using namespace std;

class Student {
protected:
    string name;
    float marks;
public:
    Student(string n, float m) {
        name = n;
        marks = m;
    }

    string getName() { return name; }
    float getMarks() { return marks; }

    virtual string computeGrade() = 0;

    void display() {
        cout << "Name  : " << name << endl;
        cout << "Marks : " << marks << endl;
        cout << "Grade : " << computeGrade() << endl;
        cout << "--------------------" << endl;
    }

    virtual ~Student() {}
};

class Undergraduate : public Student {
public:
    Undergraduate(string n, float m) : Student(n, m) {}

    string computeGrade() override {
        if (marks >= 70) return "A";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else if (marks >= 40) return "D";
        else return "F";
    }
};

class Postgraduate : public Student {
public:
    Postgraduate(string n, float m) : Student(n, m) {}

    string computeGrade() override {
        if (marks >= 80) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 60) return "C";
        else if (marks >= 50) return "D";
        else return "F";
    }
};

int main() {
    vector<Student*> records;
    int choice;

    cout << "=== Grading System ===" << endl;

    do {
        cout << "\n1. Add Undergraduate" << endl;
        cout << "2. Add Postgraduate" << endl;
        cout << "3. Show All Records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            string name;
            float marks;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter marks: ";
            cin >> marks;

            if (choice == 1)
                records.push_back(new Undergraduate(name, marks));
            else
                records.push_back(new Postgraduate(name, marks));

            cout << "Student added!" << endl;
        }
        else if (choice == 3) {
            if (records.empty()) {
                cout << "No records found." << endl;
            } else {
                cout << "\n=== All Students ===" << endl;
                for (int i = 0; i < records.size(); i++) {
                    records[i]->display();
                }
            }
        }

    } while (choice != 4);

    for (int i = 0; i < records.size(); i++) {
        delete records[i];
    }

    cout << "Goodbye!" << endl;
    return 0;
}
