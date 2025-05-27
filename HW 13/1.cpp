#include<iostream>
using namespace std;
class Int{
public:
    int a;
    Int(int b):a(b){}
    Int()
    {
        a=0;
    }
    Int(const Int &b)
    {
        a=b.a;
    }
    Int operator+(Int b)
    {
        Int c;
        c.a=a+b.a;
        return c;
    }
    Int operator-(Int b)
    {
        Int c;
        c.a=a-b.a;
        return c;
    }
    Int operator*(Int b)
    {
        Int c;
        c.a=a*b.a;
        return c;
    }
    Int operator/(Int b)
    {
        Int c;
        c.a=a/b.a;
        return c;
    }
    friend ostream& operator<<(ostream &out, const Int &obj)
    {
        out << obj.a;
        return out;
    }
    friend istream& operator>>(istream &in, Int &obj)
    {
        in >> obj.a;
        return in;
    }
};
int main()
{
    Int a=0;
    Int b=a;
    Int c;
    cin>>a>>b;
    c=a+b;
    cout<<a-b<<endl;
}