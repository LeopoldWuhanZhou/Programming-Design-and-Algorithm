#include<iostream>
using namespace std;
int t;
int a[1000][1000];
int cal(int m, int n)
{
    int res=0;
    if(a[m][n] != 0)
        return a[m][n];
    else if(m < n || m == 0 || n == 0)
    {
        a[m][n] = 0;
        return 0;
    }
    else if(m == n || n == 1)
    {
        a[m][n] = 1;
        return 1;
    }
    else
    {
        for(int i = 1; i<= m/n; i++)
        {
            for(int j = 1; j <= n-1; j++)
            {
                res += cal(m - i * n, n - j);
            }
        }
        if(m % n == 0)
        {
            res += 1;
        }
        a[m][n] = res;
        return res;
    }
}
int main()
{
    cin >> t;
    while (t > 0)
    {
        t--;
        int m, n;
        cin >> m >> n;
        int sum=0;
        for (int i = 1; i <= n; i++)
        {
            sum += cal(m, i);
        }
        cout << sum << endl;
    }
}