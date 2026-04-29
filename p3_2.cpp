#include <iostream>
using namespace std;
int total(int a[] , int n);
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array: ";
    for (int i = 0 ; i< n ; i++)
    {
        cin>>a[i];
    }
   
    cout<<"The sum of elements of array using recursion function is: "<<total(a,n)<<endl;
    //interation
    int SUM = 0;
    for (int i = 0 ; i< n ; i++)
    {
        SUM+= a[i];
    }
    
    cout<<"The sum of elements of array using iteration (for loop) is: "<<SUM<<endl;
    return 0;
}
 //recursion
int total(int a[] , int n)
{
    if (n==0)
    {
        return 0;        
    }
    else
    {
        return (a[n-1] + total(a, n-1));        
    }
}
