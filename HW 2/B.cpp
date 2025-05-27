#include<iostream>
using namespace std;
long long combination(long long n, long long m){
    if (m == 0 || m == n) {
        return 1;
    }
    return combination(n - 1, m - 1) + combination(n - 1, m);
}
int main(){
    long long n,m,res=1;
    char a;
    cin >> n >> m >> a;
    if(m==0)
    {
        if(n==0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    if (a=='P')
    {
        for(long long i=1;i<=m;i++)
            res*=(n-i+1);
        cout << res << endl;
    }
    else
    {
        cout << combination(n, m) << endl;
    }
    return 0;
}