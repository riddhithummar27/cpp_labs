#include <iostream>
using namespace std;
class student
{
    int roll;
    string name;
    int marks[3];
    float avg= 0;
    public:
    student()
    {}
    student(int r, string n, int m[3])
    {
        roll = r;
        name = n;
        for (int i = 0; i < 3 ; i++)
        {
            marks[i] = m[i];
        }
    }
    void average()
    {
        for (int i = 0; i<3; i++)
        {
            avg += marks[i];  
        }
        avg = avg / 3;
    }
    // return average to another function , it finds average everytime average() function is called
    float ave(){
        return avg;
    }
    
    char grade()
    {
        if (avg >= 90)
        {
            return 'A';
        }
        else if (avg >= 80)
        {
            return 'B';
        }
        else if (avg >= 70)
        {
            return 'C';
        }
        else if(avg >= 60)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    
    }
    void display()
    {
        cout<<"---------------------------------"<<endl;
        cout<<"Student roll number: "<<roll<<endl;
        cout<<"Student name: "<<name<<endl; 
        cout<<"Student marks: ";
        for (int i = 0 ; i< 3 ; i++)
        {
            cout<<marks[i]<< " ";
        }
        cout<< endl;
        cout<<"Average marks: "<< avg<<endl;
        cout<<"Grade: "<<this -> grade()<<endl;
        cout<<"---------------------------------"<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    student s[n];
    cout<<"DETAILS OF STUDENTS"<<endl;
    for (int i = 0; i < n ; i++)  
    {
        int ro;
        int mark[3];
        string nam;
        cout<<"Enter roll number: ";
        cin>>ro;
        cout<<"Enter name: ";
        cin>>nam;
        cout<<"Enter marks of 3 subjects: ";
        for(int i =0 ; i < 3; i++)
        {
            cin>>mark[i];
        }
        s[i] = student(ro ,nam ,mark);
        s[i].average();
    }
     for(int i = 0 ; i< n ; i++)
     {
        s[i].display();
     }
    //for highest avg
    float high= 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        if (s[i].ave() > high)
        {
            high = s[i].ave();
        }
    }
    cout<<"Higest average: "<<high<<endl;
    return 0;
    }

