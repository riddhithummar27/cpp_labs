#include<iostream>
#include<exception>
using namespace std;

int main()
{
    int a, b;

    try
    {
        cout << "Enter two numbers: ";
        cin >> a >> b;

        if(cin.fail())
        {
            throw "Invalid input. Enter integers only";
        }

        if(b == 0)
        {
            throw "Division by zero is not allowed";
        }

        cout << "Result: " << a / b << endl;
    }
    catch(const char *e)
    {
        cout << "Error: " << e << endl;
    }

    return 0;
}

