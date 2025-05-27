#include<iostream>
#include<string>
#include <cctype>
using namespace std;
int main()
{
    string a;
    bool flag = true;
    getline(cin,a);
    int location=1;
    while(flag)
    {
        if(location >= a.length()-4)
        {
            flag = false;
            break;
        }
        for(int i=location; i<a.length()-4; i++)
        {
            if(a[i]=='d' && a[i+1]=='o' && a[i+2]=='n' && a[i+3]=='\'' && a[i+4]=='t')
            {
                a = a.substr(0,i) + "do not" + a.substr(i+5, a.length());
                location = i+5;
                break;
            }
            else if(a[i]=='c' && a[i+1]=='a' && a[i+2]=='n' && a[i+3]=='\'' && a[i+4]=='t')
            {
                a = a.substr(0,i) + "can not" + a.substr(i+5, a.length());
                location = i+5;
                break;
            }
            location = i+1;
        }
    }
    for(int i=1; i<a.length()-1; i++)
    {
        if (a[i] == '-' && isalpha(a[i - 1]) && isalpha(a[i + 1])) continue;
        if (ispunct(a[i])) a[i] = ' ';
    }
    cout<<a;
    return 0;
}
