#include <iostream>
using namespace std;
class complex
{
    public:
    int real;
    int imag;
    
    complex(int r =0, int i= 0)
    {
        real = r;
        imag = i;
    }
    complex operator +(complex c1)
    {
        return complex (real + c1.real, imag + c1.imag );
    }
};
int main()
{
    complex c1(5,3), c2(4,1);
    complex c3 = c1.operator +(c2);
    cout<<c3.real<<endl<<c3.imag<<endl;
}
