#include<iostream>
using namespace std;
int T,n,k;
int m[150],p[150];
int main()
{
    cin>>T;
    while(T>0)
    {
        T--;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> m[i];
        for(int i = 0; i < n; i++)
            cin >> p[i];
        int dp[150] = {0};
        dp[0] = p[0];
        for(int i = 1; i < n; i++)
        {
            int pos = -1;
            for(int j = i-1; j >= 0; j--)
            {
                if(m[i] - m[j] > k )
                {
                    pos = j;
                    break;
                }
            }
            if(pos == -1) dp[i] = p[i];
            else dp[i] = dp[pos] + p[i];
            for(int j = pos+1; j < i; j++)
                dp[i] = max(dp[i], dp[j]);
        }
        cout << dp[n-1] << endl;
    }
}