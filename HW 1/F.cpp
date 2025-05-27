#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main() {
    double a, b;
    char op;
    string s=";";
    while(s==";") {
        cin >> a >> op >> b;
        if(op == '+') {
            cout <<fixed<<setprecision(6)<< a+b << endl;
        } else if(op == '-') {
            cout <<fixed<<setprecision(6)<< a-b << endl;
        } else if(op == '*') {
            cout <<fixed<<setprecision(6)<< a*b << endl;
        } else if(op == '/') {
            if (b != 0) {
                cout <<fixed<<setprecision(6)<< a/b << endl;
            }
        } 
        cin >> s;
    }
    return 0;
}