#include <iostream>
using namespace std;

class Complex {
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {  }

    Complex operator +(const Complex& c);
    friend ostream& operator <<(ostream& os, const Complex & c);
    friend istream& operator>>(istream& is, Complex & c);
private:
    double real;
    double imag;
};
istream& operator>>(istream& is, Complex & c)
{
    double real, imag;
    char ch1, ch2, ch3;
    is >> ch1 >> real >> ch2 >> imag >> ch3;
    if (!is) return is;                    // we didn’t get our values, so just leave
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {   // format error
        is.clear(ios_base::failbit);                // something wrong: set state to fail()
        return is;                                  // and leave
    }
    c = Complex( real, imag );     // update c
    return is;                     // and leave with is in the good() state
}

ostream & operator << (ostream& os, const Complex& c)
{
    return os << "(" << c.real << "," << c.imag << ")";
}

Complex Complex::operator + (const Complex& c)
{
    //在此处添加你的代码
    return Complex(this->real + c.real, this->imag + c.imag);
}



//测试代码，请不要修改
int main()
{
    Complex a, b;
    cin >> a >> b;

    cout << a + b << endl;

    return 0;
}