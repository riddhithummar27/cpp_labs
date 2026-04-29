#include<iostream>
#include<vector>  
using namespace std;

class Bank
{
    int Acc_No;
    string Acc_name;
    int curr_Bal;
    static int total_Acc_No;

public:

    Bank()
    {
      curr_Bal=0;
    }

    Bank(int a,string n,int b)
    {
        Acc_No=a;
        Acc_name=n;
        curr_Bal=b;
        total_Acc_No++;
    }

    int Account_no()
    {
        return Acc_No;
    }

    static int total_Ac_No()
    {
        return total_Acc_No;
    }

    void deposit(int deposit)
    {
        if(deposit>0)
        {
            curr_Bal=curr_Bal+deposit;
            cout<<"Now Bank Balance is:"<<curr_Bal;
            cout<<endl;
        }
        else
        {
            cout<<"Invalid amount";
        }
    }

    void withdraw(int withdraw)
    {
        if(withdraw>=0 && withdraw<curr_Bal){
            curr_Bal=curr_Bal-withdraw;
            cout<<"Now Bank Balance is: "<<curr_Bal;
            cout<<endl;
        }
        else
        {
            cout<<"Invalid withdraw ammount"<<endl;
        }
    }

    void display()
    {
        cout<<"\t\t================Full Account Summary========================="<<endl;
        cout<<"Account Holder Name:"<<Acc_name<<endl;
        cout<<"Account Holder ID:"<<Acc_No<<endl;
        cout<<"Current Balance:"<<curr_Bal<<endl;
    }
};

int Bank::total_Acc_No=0;

int main()
{
    int m;
    cout<<"Enter Number of Account: ";
    cin>>m;

    vector<Bank> b(m);

    int num;
    string n;
    int bal;

    for(int i=0;i<m;i++)
    {
        cout<<"Enter Account Number: ";
        cin>>num;
        cout<<"Enter Bank Holder's Name: ";
        cin>>n;
        cout<<"Enter current Balance: ";
        cin>>bal;
        cout<<endl;

        b[i]=Bank(num,n,bal);
    }

    int from;
    int to;
    int amount;

    cout<<"Enter sender''s Account Number: ";
    cin>>from;
    cout<<"Enter Reciever's Account Number: ";
    cin>>to;
    cout<<"Enter Amount for transaction: ";
    cin>>amount;

    if(from==to)
    {
        cout<<"Invalid Transaction";
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(from==b[i].Account_no())
            {
                b[i].withdraw(amount);
            }
            if(to==b[i].Account_no())
            {
                b[i].deposit(amount);
            }
        }

        for(int i=0;i<m;i++)
        {
            b[i].display();
        }
    }

    return 0;
}
