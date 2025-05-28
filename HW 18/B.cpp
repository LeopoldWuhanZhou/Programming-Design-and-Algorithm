#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    double ave = 0;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = m; i< n - m; i++)
        ave += a[i];
    ave = ave * 1.0 / (n - 2 * m);
    cout << fixed << setprecision (2)<<ave << endl;
    return 0;
}