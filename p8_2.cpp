#include <iostream>
#include <cmath>
using namespace std;

class Negative
{
public:
    const char* what() const
    {
        return "Negative number cannot have a real square root.";
    }
};

int main()
{
    double num;

    try
    {
        cout << "Enter a number: ";
        cin >> num;

        if (cin.fail())
        {
            throw "Invalid input. Enter numbers only";
        }

        if (num < 0)
        {
            throw Negative();
        }

        cout << "Square root of " << num << " is " << sqrt(num) << endl;
    }
    catch (const char* msg)
    {
        cout << "Error: " << msg << endl;
    }
    catch (const Negative& n)
    {
        cout << "Error: " << n.what() << endl;
    }

    return 0;
}
