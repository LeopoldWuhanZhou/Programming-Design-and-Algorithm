#include<iostream>
#include<cmath>
using namespace std;
int main() {
    double rice;
    cin >> rice;
    cout << ceil(log(rice)/log(2)) << endl;
    return 0;
}