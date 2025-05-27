#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class person{
    public:
    string name;
    int age;
    person(string name, int age){
        this->name = name;
        this->age = age;
    }
    person(string name){
        this->name = name;
        this->age = 0;
    }
};
int main(){
    vector<person> v;
    for(int i=0; i<5; i++){
        string name;
        cin>>name;
        person p(name);
        v.push_back(p);
    }
    for(int i=0; i<5; i++){
        int age;
        cin>>age;
        v[i].age = age;
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4-i; j++){
            if(v[j].name > v[j+1].name){
                swap(v[j], v[j+1]);
            }
        }
    }
    for(int i=0; i<5; i++){
        cout<<"("<<v[i].name<<","<<" "<<v[i].age<<") ";
    }
    return 0;
}