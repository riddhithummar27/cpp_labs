#include<iostream>
#include <string>
using namespace std;
int super (int N);
int main()
{
    int K; 
    long long num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"Enter the value of K: ";
    cin>>K;
    //int NUM = stoi(num);
    int s = 0;
    while (num > 0)
    {
        int rev = num % 10;
        num = num/10;
        s = s + rev;
    }
    s = s * K;
    cout<< super(s);
    return 0;
}
int super(int n)
{
    if(n < 10)
    {
        return n;
    }   
    else
    {
        int sum= 0;
        while(n > 0)
        {
        int rem = n % 10;
        n = n/10;
        sum = sum + rem;
        }
        return super(sum);
    }
    return 0;
}
