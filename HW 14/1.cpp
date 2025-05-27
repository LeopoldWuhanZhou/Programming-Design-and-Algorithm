#include <iostream>
using namespace std;

template <class T>
class Number {
public:
    T value;
    Number(T val) : value(val) {}
    Number() : value(0) {}
    Number(const Number& other) : value(other.value) {}
    Number operator+(const Number& other){
        return Number(value + other.value);
    }
    Number operator-(const Number& other){
        return Number(value - other.value);
    }
    Number operator*(const Number& other){
        return Number(value * other.value);
    }
    Number operator/(const Number& other){
        if (other.value == 0) {
            throw runtime_error("Division by zero");
        }
        return Number(value / other.value);
    }
    friend ostream& operator<<(ostream& os, const Number& num) {
        os << num.value;
        return os;
    }
    friend istream& operator>>(istream& is, Number& num) {
        is >> num.value;
        return is;
    }
};
int main()
{
    Number<double> x = 1.0;  
    Number<double> y = x;  
    Number<double> z;  
    z = (x + y)/ y;  
    cin >> x >> y;  
    cout << ( x + y ) / z << endl;  
}