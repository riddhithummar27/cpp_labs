 #include<iostream>
using namespace std;
class fahrenheit;
class celcius
{
    public:
    float temp;
    celcius(float t= 0)
    {
        temp = t;
    }
    operator fahrenheit();
};
class fahrenheit
{
    public:
    float temp;
    fahrenheit(float t= 0)
    {
        temp = t;
    }
    operator celcius();
};
celcius::operator fahrenheit()
{
    float f = (temp*9.0/5.0)+32;
    return fahrenheit(f);
}
fahrenheit::operator celcius()
{     float c = ((temp-32)*5.0/9.0);

    return celcius(c) ;
}
bool operator ==(celcius c1, celcius c2)
{
    if(c1.temp==c2.temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    celcius c(100);
    fahrenheit f = c;
    cout<<f.temp<<endl;
    fahrenheit f1(104);
    c = f1;
    cout<<c.temp<<endl;
    if (celcius(100)== fahrenheit(100))
    {
        cout<<"Both temperatures are equal.";
    }
    else
    {
        cout<<"Temperatures unequal.";
    }
}

