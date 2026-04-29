#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file;
    string filename;
    int totalLines = 0;
    int validLines = 0;
    int badLines = 0;
    double sum = 0;

    while (true) {
        cout << "Enter file name: ";
        cin >> filename;

        file.open(filename);

        if (file.is_open()) {
            cout << "File opened successfully!" << endl;
            break;
        } else {
            cout << "Error: File not found. Try again or type 'exit' to quit." << endl;
            if (filename == "exit") return 0;
        }
    }

    cout << endl;
    string line;

    while (getline(file, line)) {
        totalLines++;
        cout << "Line " << totalLines << ": " << line << endl;

        stringstream ss(line);
        double number;

        if (ss >> number) {
            sum += number;
            validLines++;
            cout << "   Valid number: " << number << endl;
        } else {
            badLines++;
            cout << "   ERROR: Corrupted data - not a number!" << endl;
        }
    }

    file.close();

    cout << "\n=== Summary ===" << endl;
    cout << "Total lines   : " << totalLines << endl;
    cout << "Valid lines   : " << validLines << endl;
    cout << "Bad lines     : " << badLines << endl;
    if (validLines > 0) {
        cout << "Sum           : " << sum << endl;
        cout << "Average       : " << sum / validLines << endl;
    }

    return 0;
}


