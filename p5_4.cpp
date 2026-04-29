#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& out)
{
    out << "$ "; 
    return out;
}

int main()
{
    string name[] = {"Riddhi", "Radhika", "Prachi"};
    int marks[] = {89, 76, 92};
    float fees[] = {25000.5, 23000.75, 27000.25};

    int n = 3;
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << setfill(' ');

    cout << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Fees" << endl;

    cout << setfill('-') << setw(50) << "-" << endl;
    cout << setfill(' ');
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << name[i]
             << setw(10) << marks[i]
             << setw(10) << currency 
             << fixed << setprecision(2)
             << fees[i] << endl;
    }

    cout << setfill('-') << setw(50) << "-" << endl;

    return 0;
}
