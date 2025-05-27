#include<iostream>
#include<string>
using namespace std;
int main()
{
    string word, s;
    getline(cin,word);
    int line=0;
    while(getline(cin, s))
    {
        line++;
        if(s.find(word) != -1)
            cout << line<< " " <<s<< endl;
    }
}