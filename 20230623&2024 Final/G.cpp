#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int k,w,s;
double n[200],v[200];
int main()
{
    cin >> k;
    while(k>0)
    {
        double value=0;
        k--;
        cin >> w >> s;
        for(int i=0; i<s; i++)
            cin >> n[i] >> v[i];
        for(int i=0; i<s; i++)
        {
            for(int j=0; j<s-i-1; j++)
            {
                if(v[j]/n[j] < v[j+1]/n[j+1])
                {
                    double temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                    temp = n[j];
                    n[j] = n[j+1];
                    n[j+1] = temp;
                }
            }
        }
        while(w>0)
        {
            for(int i=0; i<s; i++)
            {
                if(n[i] <= w)
                {
                    value += v[i];
                    w -= n[i];
                }
                else
                {
                    value += w * (v[i] *1.0 / n[i]);
                    w = 0; 
                    break;
                }
            }
            break;
        }
        cout << fixed << setprecision(2) << value << endl;
    }
    return 0;
}