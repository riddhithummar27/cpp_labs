#include <iostream>
using namespace std;

class Wallet {
private:
    int id;
    string name;
    double balance;

public:
    Wallet(int i, string n) {
        id = i;
        name = n;
        balance = 0;
    }

    void load(double amt) {
        balance += amt;
    }

    void transfer(Wallet &w, double amt) {
        if (balance >= amt) {
            balance -= amt;
            w.balance += amt;
            cout << "Transfer done\n";
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void display() {
        cout << id << " " << name << " Balance: " << balance << endl;
    }
};

int main() {
    Wallet w1(1, "A"), w2(2, "B");

    w1.load(1000);
    w1.transfer(w2, 500);

    w1.display();
    w2.display();

    return 0;
}
