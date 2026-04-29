#include<iostream>
#include <string>
using namespace std;

class emp
{
    string name;
    float b_sal;
    float bonus;
    public:
    emp()
    {
        b_sal = 0;
        bonus= 0;
    }
    emp(string n, float sal, float boNus = 2000.0)
    {
        name  = n;
        do{
            b_sal = sal;
        }while(sal < 0);
        bonus = boNus;
    }
    float Total_sal()
    {
        return (b_sal + bonus);
    }
    float bonus_u(){
        return 5000.0;
    }
    void display()
    {
        cout<<"Employee name: "<<name<<endl;
        cout<<"Employee basic salary: "<<b_sal<<endl;
        cout<<"Employee bonus: "<<bonus<<endl;
        float a=Total_sal();
        cout<<"Employee Total salary: "<<a<<endl;
    }
};

int main()
{
    int n = 2;
    emp e[n];
    for (int i = 0 ;i< n ; i++)
    {
        string Name;
        float Basic_sal;
        float BonUs;
        int work_days;
        cout<<"Enter the name of employee: ";
        cin>>Name;
        cout<<"Enter the basic salary of employee: ";
        cin>>Basic_sal;
        cout<<"Enter the number of working days of employee: ";
        cin>>work_days;
        if (work_days > 90)
        {
            BonUs = e[i].bonus_u();
        }
        else
        {
            BonUs = 2000.0;
        }
        e[i] = emp(Name, Basic_sal, BonUs);
        cout<<"-------EMPLOYEE DETAILS--------"<<endl<<e[i].display();
    }
    return 0;
}
