#include <iostream>
using namespace std;

class rectangle
{
    private:
    double length, width; 
    public:
    rectangle()
    {
        length = 0;
        width = 0;
    }
    void set_dim(double l , double w)
    {
        if(l > 0 && w> 0)
        {
            length =l;
            width = w;
        }
        else
        {
            cout<<"Dimensions can not be negative."<<endl;
        }
        
    }
    double area()
    {
        return length * width;
    }
    double per()
    {
        return 2 * (length + width);
    }
    bool isSquare()
    {
        return length == width;
    }
    void display()
    {
        cout<< "Area: "<< area()<<endl;
        cout<< "Perimeter: "<< per()<<endl;
        if (isSquare())
        {
            cout<<"This R is a square."<<endl;
        }
        else
        {
            cout<<"This R is not a square."<<endl;
        }
    }
};
int main()
{
    int n;
    cout<<"Enter number of rectangle: ";
    cin>>n;
    rectangle r[n];
    double len , wid;
    for (int i = 0 ; i< n; i++)
    {
        cout<<"Enter for rectangle " << i+1<<endl;
        cout<< "Length: ";
        cin>> len;
        cout<< "Width: ";
        cin>> wid;
        r[i].set_dim(len, wid);
    }
    for (int i = 0 ; i <n ; i++)
    {
        cout<<endl<<"----------------"<< endl;
        cout<< "Rectangle" << i+1<<endl;
        r[i].display();
        cout<<endl<<"----------------"<< endl;
    }
    int max_area = 0;
    int temp;
    // to find max area from first two rectangles
    for (int i = 0; i< 2 ;i++)
    {
        if (r[i].area() > max_area)
        {
            max_area = r[i].area();
            temp = i;
        }
    }
    cout<< "Rectangle with maximum area: "<< temp +1 <<endl;
    cout<<"Maximum area: "<< max_area<<endl;
    return 0;
}
