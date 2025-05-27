#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0;
    for(int m=0;m<s.length();m++){
        if(isspace(s[m])){
            a++;
        }
        if(isalpha(s[m])){
            b++;
        }
        if(isdigit(s[m])){
            c++;
        }
        if(isxdigit(s[m])){
            d++;
        }
        if(isupper(s[m])){
            e++;
        }
        if(islower(s[m])){
            f++;
        }
        if(isalnum(s[m])){
            g++;
        }
        if(iscntrl(s[m])){
            h++;
        }
        if(ispunct(s[m])){
            i++;
        }
        if(isprint(s[m])){
            j++;
        }
        if(isgraph(s[m])){
            k++;
        }
    }
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl<<i<<endl<<j<<endl<<k;
    return 0;
}
