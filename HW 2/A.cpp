#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if (s1==s2)
    {
        cout <<"Continue again!" << endl;
    }
    else if (s1=="Rock")
    {
        if(s2=="Scissors")
        {
            cout << "You win!" << endl;
        }
        else
        {
            cout << "You lose!" << endl;
        }
    }
    else if (s1=="Scissors")
    {
        if(s2=="Paper")
        {
            cout << "You win!" << endl;
        }
        else
        {
            cout << "You lose!" << endl;
        }
    }
    else if (s1=="Paper")
    {
        if(s2=="Rock")
        {
            cout << "You win!" << endl;
        }
        else
        {
            cout << "You lose!" << endl;
        }
    }
    return 0;
}