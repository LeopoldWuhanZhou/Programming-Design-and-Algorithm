#include<iostream>
#include<string>
using namespace std;
int t,k;
string s;
int main()
{
    cin>>t;
    while(t>0)
    {
        t--;
        cin>>s>>k;
        while(k>0)
        {
            for(int i=0; i < s.size(); i++)
            {
                if(i== s.size()-1||s[i] > s[i+1])
                {
                    s.erase(i, 1);
                    k--;
                    break;
                }
            }
        }
        cout<<s<<endl;   
    }
    return 0;
}