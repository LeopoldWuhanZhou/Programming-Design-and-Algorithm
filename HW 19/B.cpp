#include<iostream>
using namespace std;
int n,k;
int board[8][8];
int row[8], col[8];
int c;
void dfs(int i, int j, int num)
{
    if (num == k) 
    {
        c++;
        return;
    }
    for(int x = i; x < n; x++)
    {
        if (x == i)
        {
            for(int y = j; y < n; y++)
            {
                if(board[x][y] == 1 && row[x] == 0 && col[y] == 0)
                {
                    row[x] = 1;
                    col[y] = 1;
                    dfs(x+1, 0, num + 1);
                    row[x] = 0;
                    col[y] = 0;
                }
            }
        }
        else
        {
            for(int y = 0; y < n; y++)
            {
                if(board[x][y] == 1 && row[x] == 0 && col[y] == 0)
                {
                    row[x] = 1;
                    col[y] = 1;
                    dfs(x+1, 0, num + 1);
                    row[x] = 0;
                    col[y] = 0;
                }
            }
        }
    }
    return;
}
int main()
{
    while(cin>>n>>k)
    {
        if (n == -1 && k == -1) break;
        c=0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                char c;
                cin>>c;
                if (c == '#') board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
        dfs(0, 0, 0);
        cout<<c<<endl;
    }
    return 0;
}