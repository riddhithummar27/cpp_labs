#include<iostream>
#include<string>
using namespace std;
class fuel
{
    protected:
    string type;
    public:
    fuel(string t)
    {
        type = t;
    }
    void display()
    {
        cout<<"Fuel Type: "<<type<<endl;
    }
};
class brand 
{
    protected:
    string model;
    public:
    brand(string m) 
    {
        model = m;
    }
    void displayB()
    {
        cout<<"Model: "<<model<<endl;
    }
};
class car : public fuel, public brand
{
    private:
    int id;
    public:
    car(string t, string m, int n) : fuel(t), brand(m)
    {
        id =n;
    }
    void displayCAR()
    {
        cout<<"-----------------------------------"<<endl;
        display();
        displayB();
        cout << "ID: " << id << endl;
        cout<<"------------------------------------"<<endl;
    }
    int getid()
    {
        return id;
    }
};
int main()
{
    car c[3] = {car("Petrol", "Toyota", 102), car("Diesel", "Honda", 103) ,car("Petrol", "KIA",108)};
    for(int i = 0 ; i < 3; i++)
    {
        c[i].displayCAR();
        cout<<endl;
    }
    int search;
    cout<<"Enter ID to search: "<<endl;
    cin>>search;
    int flag = false;
    for (int i = 0 ; i <3 ; i++)
    {
        if(c[i].getid() == search)
        {
            cout<<"Car Found"<<endl;
            c[i].displayCAR();
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout<<"Car not found"<<endl;
    }
    return 0;
}
