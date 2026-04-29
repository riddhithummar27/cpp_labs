#include<iostream>
using namespace std;
class calc
{
    public:
    int a, b;
    float c , d;
    int add(int a,int b)
    {
        return (a+b);
    }
    float add(float c,float d)
    {
        return(c+d);    
    }
};
int main()
{
    calc obj;
    cout<<obj.add(4,7)<<endl;
    cout<<obj.add(float(10.1),float(9.9));
    return 0;
}
