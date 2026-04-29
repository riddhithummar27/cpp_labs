#include<iostream>
#include<string>
using namespace std;
class item
{
    public:
    int id;
    string name;
    float price;
    int qty;
    item()
    {}
    item(int i, string n, float p , int q)
    {
        id = i; 
        name = n ;
        price = p;
        qty = q;
    }
    void display()
    {
        cout<<"------------------------------"<<endl;
        cout<<"ID"<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Quantity: "<<qty<<endl;
        cout<<"------------------------------"<<endl;
    }
    void add()
    {
        qty++;
        cout<<"Item added to stock."<<endl;
        display();
    }
    void remove()
    {
        if (qty>0)
        {
            qty--;
            cout<<"Item removed from stock."<<endl;
            display();
        }
        else
        {
            cout<<"Stock is empty."<<endl;
        }
    }
    int check()
    {
        if (qty < 5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    item items[n];
    for (int i = 0; i < n; i++)
    {
        int id;
        string name;
        float price;
        int qty;
        cout<<"Enter details for item "<<i+1<<":"<<endl;
        cout<<"ID: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        cout<<"Price: ";
        cin>>price;
        cout<<"Quantity: ";
        cin>>qty;
        items[i] = item(id, name, price, qty);
    }
    bool flag = true;
    while(flag)
    {
        int choice;
        cout<<"Choose an option: "<<endl;
        cout<<"1. Add item to stock"<<endl; 
        cout<<"2. Remove item from stock"<<endl;
        cout<<"3. Display item details"<<endl;  
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int ID;
                cout<<"Enter item ID to add: ";
                cin>>ID;
                for (int i = 0; i <n ; i++)
                {
                    if (items[i].id == ID)
                    {
                        items[i].add();
                        break;
                    }
                    else
                    {
                        cout<<"Item not found."<<endl;
                    }
                }
                break;
            }
            case 2:
            {
                int ID;
                cout<<"Enter item ID to remove: ";
                cin>>ID;
                for (int i = 0; i <n ; i++)
                {
                    if (items[i].id == ID)
                    {
                        items[i].remove();
                    }
                    else
                    {
                        cout<<"Item not found."<<endl;
                    }
                }
                break;
            }
            case 3:
            {
                int ID;
                cout<<"Enter item ID to display: ";
                cin>>ID;
                for (int i = 0; i <n ; i++)
                {
                    if (items[i].id == ID)
                    {
                        items[i].display();
                    }
                    else
                    {
                        cout<<"Item not found."<<endl;
                    }
                }
                break;
            }
            case 4:
            {
                flag = false;
                cout<<"Exiting program."<<endl;
                break;
            }
        }
    }
    //for items with stock < 5
    for(int i = 0 ; i < n ; i++)
    {
        if (items[i].check() == 1)
        {
            cout<<"Item "<<items[i].id<<" is low in stock."<<endl;
        }
    }
}
