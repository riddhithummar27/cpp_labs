#include <iostream>
using namespace std;

class BaseNoVirtual {
public:
    BaseNoVirtual() {
        cout << "Base constructor called" << endl;
    }
    ~BaseNoVirtual() {
        cout << "Base destructor called" << endl;
    }
};

class DerivedNoVirtual : public BaseNoVirtual {
    int* resource;
public:
    DerivedNoVirtual() {
        resource = new int(100);
        cout << "Derived constructor called - resource created" << endl;
    }
    ~DerivedNoVirtual() {
        delete resource;
        cout << "Derived destructor called - resource deleted" << endl;
    }
};

class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }
    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
    int* resource;
public:
    Derived() {
        resource = new int(100);
        cout << "Derived constructor called - resource created" << endl;
    }
    ~Derived() {
        delete resource;
        cout << "Derived destructor called - resource deleted" << endl;
    }
};

int main() {
    cout << "===  WITHOUT virtual destructor (resource leak!) ===" << endl;
    BaseNoVirtual* p1 = new DerivedNoVirtual();
    delete p1;

    cout << endl;

    cout << "=== WITH virtual destructor (safe cleanup) ===" << endl;
    Base* p2 = new Derived();
    delete p2;

    return 0;
}


