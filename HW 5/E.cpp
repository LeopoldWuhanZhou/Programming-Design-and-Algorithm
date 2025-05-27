#include<iostream>
#include<iomanip>
using namespace std;
class fraction{
public:
    int a,b;
};
ostream & operator <<(ostream& os, const fraction& c)
{
    os<<c.a<<"/"<<c.b<<"("<<fixed<<setprecision(6)<<(double)c.a/(double)c.b<<")";
    return os;
}
fraction operator+(const fraction &A, const fraction &B){
    fraction c;
    c.a = A.a*B.b + B.a*A.b;
    c.b = A.b*B.b;
    return c;
}
fraction operator-(const fraction &A, const fraction &B){
    fraction c;
    c.a = A.a*B.b - B.a*A.b;
    c.b = A.b*B.b;
    return c;
}
fraction operator*(const fraction &A, const fraction &B){
    fraction c;
    c.a = A.a*B.a;
    c.b = A.b*B.b;
    return c;
}
fraction operator/(const fraction &A, const fraction &B){
    fraction c;
    c.a = A.a*B.b;
    c.b = A.b*B.a;
    return c;
}
fraction simplify (const fraction &A){
    fraction c;
    int a = A.a, b = A.b;
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    c.a = A.a/a;
    c.b = A.b/a;
    return c;
}
int main(){
    fraction a, b;
    char c,op;
    cin>>a.a>>c>>a.b>>op>>b.a>>c>>b.b;
    fraction A,B;
    A = simplify(a);
    B = simplify(b);
    switch(op){
        case '+':
            cout<<simplify(A+B)<<endl;
            break;
        case '-':
            cout<<simplify(A-B)<<endl;
            break;
        case '*':
            cout<<simplify(A*B)<<endl;
            break;
        case '/':
            cout<<simplify(A/B)<<endl;
            break;
    }
    return 0;
}