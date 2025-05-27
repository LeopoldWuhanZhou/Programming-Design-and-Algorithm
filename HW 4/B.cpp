#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    int price,weight,sum=0;
    for(int i=0; i<3; i++)
    {
        cin>>price;
        v.push_back(price);
    }
    for(int i=0; i<3; i++)
    {
        cin>>weight;
        sum += v[i]*weight;
    }
    cout<<sum<<endl;
    return 0;
}