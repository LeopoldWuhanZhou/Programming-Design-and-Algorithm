#include<iostream>
using namespace std;
int N;
int a[60][60] = {0};
int dfs(int n, int k)
{
    if(a[n][k] != 0) return a[n][k];
    if(n == 1 || k == 1) 
    {
        a[n][k] = 1;
        return 1;
    }
    int ans = 0;
    for(int i = 1; i <= min(k,n); i++)
    {
        if(i == 1) ans ++;
        else
        {
            for(int j = 1; j <= n/i; j++)
            {
                if(n == i*j) ans++;
                else ans += dfs(n - i*j, i - 1);
            }
        }
    }
    a[n][k] = ans;
    return ans;
}
int main()
{
    while(cin>>N)
    {
        cout << dfs(N,N) << endl;
    }
    return 0;
}