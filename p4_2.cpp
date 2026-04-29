#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    Point* move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        return this;
    }

    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    double distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }

    void setPoint(int newX, int newY) {
        this->x = newX;
        this->y = newY;
    }

    friend void resetPoint(Point* p);
};

void resetPoint(Point* p) {
    p->setPoint(0, 0);
}

int main() {
    Point p(1, 2);

    p.display();

    p.move(2, 3)->move(-1, 4)->move(5, -2);

    p.display();

    cout << p.distanceFromOrigin() << endl;

    resetPoint(&p);

    p.display();

    return 0;
}

