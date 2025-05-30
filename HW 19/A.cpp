#include<iostream>
using namespace std;
int n;
int sum = 0;
int a[50][30];
void dfs (int i, int j, int step)
{
    a[i][j] = 1;
    if (step == n)
    {
        sum++;
        a[i][j] = 0;
        return;
    }
    if (a[i - 1][j] == 0)
        dfs(i - 1, j, step + 1);
    if (a[i + 1][j] == 0)
        dfs(i + 1, j, step + 1);
    if (a[i][j + 1] == 0)
        dfs(i, j + 1, step + 1);
    a[i][j] = 0;
    return;
}
int main()
{
    cin>>n;
    dfs (25, 0, 0);
    cout<<sum<<endl;
    return 0;
}