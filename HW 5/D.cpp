#include<iostream>
#include<vector>
#include<string>
using namespace std;
class patron{
    public:
    string name, number, fee;
    patron(string name, string number, string fee){
        this->name = name;
        this->number = number;
        this->fee = fee;
    }
};
int main()
{
    vector<patron> v;
    string name, number, fee;
    for(int i=0; i<3; i++){
        cin>>name>>number>>fee;
        if(fee!="0")
        {
            patron s(name, number, fee);
            v.push_back(s);
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size()-1-i; j++){
            if(v[j].fee>v[j+1].fee){
                swap(v[j], v[j+1]);
            }
        }
    }
    for(int i=v.size()-1; i>=0; i--){
        cout<<v[i].name<<" "<<v[i].number<<" "<<v[i].fee<<endl;
    }
    return 0;
}