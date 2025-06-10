#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string res[100];
    string s, word;
    int sum=0;
    getline(cin, s);
    for(int i=0; i < s.length(); i++)
    {
        if(s[i]==' '||s[i]==','||s[i]=='.'||s[i]=='!')
        {
            if (!word.empty()) 
            {
                bool found = false;
                for(int j = 0; j < sum; ++j) 
                {
                    if(res[j] == word) 
                    {
                        found = true;
                        break;
                    }
                }
                if(!found) res[sum++] = word;
                word.clear();
            }
        }
        else if (s[i]>='A'&&s[i]<='Z') word.push_back(tolower(s[i]));
        else word.push_back(s[i]);
    }
    sort(res, res+sum);
    for(int i=0; i< sum ;i++)
        cout<<res[i]<<endl;
    return 0;
}

