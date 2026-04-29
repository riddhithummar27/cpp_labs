#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("input.txt"); 
    if (!file)
    {
        cout << "Error: File could not be opened." << endl;
        return 1;
    }

    string line;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    while (getline(file, line))
    {
        lineCount++;

        bool inWord = false;

        for (int i = 0; i < line.length(); i++)
        {
            charCount++;
            if (line[i] != ' ' && line[i] != '\t')
            {
                if (!inWord)
                {
                    wordCount++;
                    inWord = true;
                }
            }
            else
            {
                inWord = false;
            }
        }
    }

    file.close();

    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters: " << charCount << endl;

    return 0;
}

