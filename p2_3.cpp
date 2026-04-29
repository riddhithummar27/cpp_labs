#include<iostream>
using namespace std;

class account
{
    string name;
    int acc_id;
    float balance;
    int count;
    string transaction[3];
    public:
    account()
    {
        cout<<"Account ID: ";
        cin>>acc_id;
        cout<<"Account holder name: ";
        cin>> name;
        cout<<"Account balance: " ;
        cin>> balance;
    }
    void display()
    {
        cout<<"ACCOUNT DETAILS"<<endl;
        cout<<"Account ID: "<<acc_id<<endl;
        cout<<"Account holder name: "<<name<<endl;
        cout<<"Account balance: "<<balance<<endl;
        cout<<"------------------------------"<<endl;
    }
    void deposit(int amt)
    {        
        balance = balance+ amt;
        cout << "Balance = " << balance << endl;
    }
    void withdraw(int amt)
    {
        if (balance >= amt)
        {
            balance = balance - amt;
            cout << "Balance = " << balance << endl;
        }
        else
        {   
            cout<< "Balance not available.";
        }
    }
    string status()
    {
        if (balance > 0) 
        {
            return "Active";
        }
        else
        {
            return "Inactive";
        }
    }
};

int main()
{
    int n = 2;
    account a[n];
    bool Flag = true; 
    while(Flag)
    {
        int choice;
        cout<<"Choose: "<<endl;
        cout<<"1. Withdraw "<<endl;
        cout<<"2. Deposit "<<endl;
        cout<<"3. Display "<<endl;
        cout<<"4. Status "<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        for (int i = 0; i < n ; i++)
        {
            switch(choice)
            {
            case 1:
                {
                int amt;
                cout<<"Enter amount to withdraw: ";
                cin>>amt;
                a[i].withdraw(amt);
                a[i].display();  
                break;                      
                }
                case 2:
                {
                    int amt;
                    cout<<"Enter amount to deposit: ";
                    cin>>amt;
                    a[i].deposit(amt);
                    a[i].display();
                    break;
                }
                case 3:
                {
                   a[i].display();
                   break;
                }
                case 4:
                {
                    cout<< a[i].status()<<endl;
                    break;
                }
                case 5:
                {
                    Flag = false;
                    return 0;
                }
            }
        }
    }
}    
