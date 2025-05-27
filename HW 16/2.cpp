#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct grade{
    string id;
    int a,b,c;
    double average;
    grade(string s,int x,int y,int z):id(s),a(x),b(y),c(z),average((a*2.0+b*3+c*4)/9){}
    bool operator<(const grade &g) const
    {
        return average>g.average;
    }
};
int main()
{
    string s;
    int x,y,z;
    vector<grade> v;
    while(cin>>s)
    {
        cin>>x>>y>>z;
        v.push_back(grade(s,x,y,z));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i].id<<" "<<v[i].average<<" "<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<endl;
}