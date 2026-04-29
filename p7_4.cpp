 #include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
    virtual string Name() const = 0;
    virtual ~Shape() {}

    void PrintInfo() const {
        cout << "Shape     : " << Name()      << "\n";
        cout << "Area      : " << Area()      << "\n";
        cout << "Perimeter : " << Perimeter() << "\n";
        cout << "--------------------\n";
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area()      const override { return length * width; }
    double Perimeter() const override { return 2 * (length + width); }
    string Name()      const override { return "Rectangle (" + to_string(length) + " x " + to_string(width) + ")"; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area()      const override { return M_PI * radius * radius; }
    double Perimeter() const override { return 2 * M_PI * radius; }
    string Name()      const override { return "Circle (r=" + to_string(radius) + ")"; }
};

void demoPolymorphism() {
    cout << "\n=== Demo A: Basic Polymorphism ===\n\n";
    Shape* s1 = new Rectangle(5.0, 3.0);
    Shape* s2 = new Circle(4.0);
    s1->PrintInfo();
    s2->PrintInfo();
    delete s1;
    delete s2;
}

void demoDynamicCollection() {
    cout << "\n=== Demo B: Dynamic Collection (vector) ===\n\n";
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Rectangle>(7.0, 2.0));
    shapes.push_back(make_unique<Circle>(3.5));
    shapes.push_back(make_unique<Rectangle>(4.0, 4.0));
    for (const auto& shape : shapes)
        shape->PrintInfo();
    cout << "Total shapes: " << shapes.size() << "\n";
}

void demoStaticCollection() {
    cout << "\n=== Demo C: Static Collection (array) ===\n\n";
    const int SIZE = 3;
    Shape* staticShapes[SIZE];
    staticShapes[0] = new Rectangle(10.0, 4.0);
    staticShapes[1] = new Circle(2.0);
    staticShapes[2] = new Rectangle(5.0, 5.0);
    for (int i = 0; i < SIZE; i++)
        staticShapes[i]->PrintInfo();
    for (int i = 0; i < SIZE; i++)
        delete staticShapes[i];
    cout << "Array size is fixed at: " << SIZE << "\n";
}

int main() {
    cout << "=== Practical 7.4: Shape Polymorphism ===";
    demoPolymorphism();
    demoDynamicCollection();
    demoStaticCollection();
    return 0;
}

