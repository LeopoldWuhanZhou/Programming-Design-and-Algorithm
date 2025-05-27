#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
enum class Genre{
    fiction=1, nonfiction, periodical, biography, children
};
class book{
    public:
    string name, author, ISBN, time;
    Genre genre;
    book(string name, string author, string ISBN, string time, Genre genre){
        this->name = name;
        this->author = author;
        this->ISBN = ISBN;
        this->time = time;
        this->genre = genre;
    }
};
bool operator== (const book &a, const book &b){
    return a.ISBN==b.ISBN;
}
bool operator!= (const book &a, const book &b){
    return a.ISBN!=b.ISBN;
}
ostream & operator <<(ostream& os, const book& c)
{
    os<<c.name<<" "<<c.author<<" "<<c.ISBN<<" "<<c.time<<" ";
    switch (c.genre)
	{
	case Genre::fiction:
		os << "fiction" << endl;
		break;
	case Genre::nonfiction:
		os << "nonfiction" << endl;
		break;
	case Genre::biography:
		os << "biography" << endl;
		break;
	case Genre::children:
		os << "children" << endl;
		break;
	case Genre::periodical:
		os << "periodical" << endl;
		break;
	default:
		break;
	}
    return os;
}
int main(){
    vector<book> v;
    string name, author, ISBN, time, genre_;
    Genre genre;
    for(int i=0; i<3; i++){
        cin>>name>>author>>ISBN>>time>>genre_;
        if(genre_=="fiction"){
            genre = Genre::fiction;
        }
        else if(genre_=="nonfiction"){
            genre = Genre::nonfiction;
        }
        else if(genre_=="biography"){
            genre = Genre::biography;
        }
        else if(genre_=="children"){
            genre = Genre::children;
        }
        else if(genre_=="periodical"){
            genre = Genre::periodical;
        }
        book b(name, author, ISBN, time, genre);
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
        cout<<v[i];
    }
    return 0;
}