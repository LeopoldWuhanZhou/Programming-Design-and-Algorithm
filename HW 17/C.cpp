#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double n, m, k;
    cin >> n >> m >> k;
    double x;
    x = floor((n-m)/k) + 1;
    cout<< x * n - m << endl;
    return 0;
}