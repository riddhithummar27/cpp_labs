#include <iostream>
using namespace std;

class Shape
{
protected:
    float radius;

public:
    void setRadius(float r)
    {
        radius = r;
    }

    float getRadius()
    {
        return radius;
    }
};

class Circle : public Shape
{
public:
    float area()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    cout << "\n--- Static Array ---\n";

    Circle staticCircles[100];

    for (int i = 0; i < n; i++)
    {
        float r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        staticCircles[i].setRadius(r);
    }

    cout << "\nAreas (Static):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Circle " << i + 1 << ": "
             << staticCircles[i].area() << endl;
    }

    cout << "\n--- Dynamic Array ---\n";

    Circle* dynamicCircles = new Circle[n];

    for (int i = 0; i < n; i++)
    {
        float r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        dynamicCircles[i].setRadius(r);
    }

    cout << "\nAreas (Dynamic):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Circle " << i + 1 << ": "
             << dynamicCircles[i].area() << endl;
    }

    delete[] dynamicCircles;

    return 0;
}

   
