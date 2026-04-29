#include<iostream>
#include<string>
using namespace std;
string toLower(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    return str;
}
int main()
{
    string s; 
    getline(cin, s);
    int cnt = 0;
    int n = s.length();
    string f_word[n];
    string temp;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            f_word[cnt] = toLower(temp);
            cnt++;
            temp="";
        }
    }
    if(temp!= "")
    {
        f_word[cnt] = toLower(temp);
        cnt++;
    }
    //initialize the boolean array to false, for duplicate word count
    bool word[cnt];
    for (int i = 0 ; i < cnt ; i++)
    {
        word[i] = false;
    }

    for (int i = 0 ; i < cnt ; i++)
    {
        if(word[i]== false)
        {
            int count = 1;
        for (int j = i + 1 ; j < cnt ; j++)
        {
            if (f_word[i] == f_word[j])
            {
                word[j] = true;
                count++;
            }
        }
        cout<<f_word[i]<<" "<<count<<endl;
    }
    }
}
