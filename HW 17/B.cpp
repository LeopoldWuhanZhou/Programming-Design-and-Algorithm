#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double x;
    for (x = -100; x <= 100; x += 0.01)
    {
        double res = a * x * x * x + b * x * x + c * x + d;
        if (res <=  0.0001 && res >= -0.0001)
        {
            cout <<fixed << setprecision(2) << x << " ";
            x += 0.01;
        }
    }
    return 0;
}