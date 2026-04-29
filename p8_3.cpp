#include <iostream>
#include <string>
using namespace std;

string logs[100];
int logCount = 0;

void addLog(string message) {
    logs[logCount] = message;
    logCount++;
}

class BankAccount {
    string owner;
    double balance;
public:
    BankAccount(string name, double amount) {
        owner = name;
        balance = amount;
    }

    void deposit(double amount) {
        addLog(">> deposit() called");
        if (amount <= 0) {
            addLog("!! deposit() failed - invalid amount");
            throw string("Deposit amount must be greater than zero!");
        }
        balance += amount;
        addLog("   Deposited: " + to_string(amount));
        addLog("<< deposit() done");
    }

    void withdraw(double amount) {
        addLog(">> withdraw() called");
        if (amount <= 0) {
            addLog("!! withdraw() failed - invalid amount");
            throw string("Withdrawal amount must be greater than zero!");
        }
        if (amount > balance) {
            addLog("!! withdraw() failed - insufficient funds");
            throw string("Insufficient funds! Balance: " + to_string(balance));
        }
        balance -= amount;
        addLog("   Withdrawn: " + to_string(amount));
        addLog("<< withdraw() done");
    }

    void showBalance() {
        cout << "Owner   : " << owner << endl;
        cout << "Balance : " << balance << endl;
    }
};

void doWithdraw(BankAccount& acc, double amount) {
    addLog(">> doWithdraw() called");
    acc.withdraw(amount);
    addLog("<< doWithdraw() done");
}

void doDeposit(BankAccount& acc, double amount) {
    addLog(">> doDeposit() called");
    acc.deposit(amount);
    addLog("<< doDeposit() done");
}

void printLogs() {
    cout << "\n=== Transaction Logs ===" << endl;
    for (int i = 0; i < logCount; i++) {
        cout << logs[i] << endl;
    }
}

int main() {
    BankAccount acc("John", 1000);

    cout << "=== Banking System ===" << endl;
    acc.showBalance();
    cout << endl;

    cout << "--- Depositing 500 ---" << endl;
    try {
        doDeposit(acc, 500);
        cout << "Deposit successful!" << endl;
    } catch (string e) {
        cout << "Error: " << e << endl;
    }

    cout << "\n--- Withdrawing 200 ---" << endl;
    try {
        doWithdraw(acc, 200);
        cout << "Withdrawal successful!" << endl;
    } catch (string e) {
        cout << "Error: " << e << endl;
    }

    cout << "\n--- Withdrawing 5000 (will fail) ---" << endl;
    try {
        doWithdraw(acc, 5000);
        cout << "Withdrawal successful!" << endl;
    } catch (string e) {
        cout << "Error: " << e << endl;
    }

    cout << "\n--- Final Balance ---" << endl;
    acc.showBalance();

    printLogs();

    return 0;
}

