#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> count(const vector<string>& v) 
{
    vector<int> res;
    for(int i=0; i<v.size(); i++)
    {
        res.push_back(v[i].length());
    }
    return res;
}
int main()
{
    vector<string> v;
    string s;
    for(int i=0;i<5;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    vector<int> res = count(v);
    for(int i=0; i<5; i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4-i;j++)
        {
            if(res[j]>res[j+1])
            {
                swap(res[j], res[j+1]);
                swap(v[j], v[j+1]);
            }
        }
    }
    cout<<v[4]<<" "<<v[0]<<" ";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            if(v[j]>v[j+1])
            {
                swap(v[j], v[j+1]);
            }
        }
    }
    cout<<v[0]<<" "<<v[4]<<" ";
    return 0;
}