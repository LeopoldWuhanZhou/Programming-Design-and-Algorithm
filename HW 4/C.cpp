#include<iostream>
#include<vector>
using namespace std;
int maxv(const vector<int>& v) 
{
    int max = v[0];
    for(int i=1; i<v.size(); i++)
    {
        if(v[i]>max)
        {
            max = v[i];
        }
    }
    return max;
}
int main()
{
    vector<int> v;
    int a;
    for(int i=0;i<8;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    cout<<maxv(v)<<endl;
    return 0;
}