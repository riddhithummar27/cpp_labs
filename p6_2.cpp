#include<iostream>
#include <string>
using namespace std;
class person
{
    protected:
    string name;
    int age;
    public:
    person(string n, int a)
    {
        name = n;
        age = a;
    }
    void display()
    {
        cout<<"-----------------------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age <<endl;
    }
};

class employee : public person
{
    protected:
    int empid;
    public:
    employee(string n, int a, int id) : person(n, a)
    {
        empid = id;
    }
    void displayEmp()
    {
        display();
        cout<<"ID: "<<empid<<endl;
    }
    int getEmpid()
    {
        return empid;
    }
};
class manager : public employee
{
    protected:
    string department;
    public:
    manager(string n, int a, int id, string d) : employee(n, a, id)
    {
        department = d;
    }
    void displayMan()
    {
        displayEmp();
        cout<<"Department: "<<department<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
    string getdept()
    {
        return department;
    }
};
int main()
{
    manager m[2] = {manager("Riddhi", 20, 101, "HR"), manager("radhi", 12, 102, "Finance")};
    //displaying details of all managers
    cout<<"DETAILS OF MANAGERS"<<endl;
    for (int i = 0 ; i < 2; i++)
    {
        m[i].displayMan();
        cout<<endl;
    }
    //searching for a manager by department
    bool flag = false;
    string dept;
    cout<<"Enter department to search: ";
    cin>>dept;
    for(int i = 0 ; i < 2 ; i++)
    {
       if(m[i].getdept() == dept)
       {
        cout<<"Manager found"<<endl;
        m[i].displayMan();
        flag = true;
        break;
       }
    }
    if (!flag)
    {
        cout<<"Manager not found"<<endl;
    }
    return 0;
}

