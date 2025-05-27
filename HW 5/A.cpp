#include<iostream>
#include<string>
#include<vector>
using namespace std;
class book{
    public:
    string name, author, ISBN, time;
    book(string name, string author, string ISBN, string time){
        this->name = name;
        this->author = author;
        this->ISBN = ISBN;
        this->time = time;
    }
};
int main(){
    vector<book> v;
    string name, author, ISBN, time;
    for(int i=0; i<3; i++){
        cin>>name>>author>>ISBN>>time;
        book b(name, author, ISBN, time);
        v.push_back(b);
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2-i; j++){
            if(v[j].ISBN>v[j+1].ISBN){
                swap(v[j], v[j+1]);
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i].name<<" "<<v[i].author<<" "<<v[i].ISBN<<" "<<v[i].time<<endl;
    }
    return 0;
}