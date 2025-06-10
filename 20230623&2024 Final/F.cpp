#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;
struct Score{
  int ID;
  vector<double> s;
  double average ;
};

istream& operator >>(istream& is, Score &a)
{
  double s1, s2, s3;
  is >> a.ID >> s1 >> s2 >> s3;
  a.s.push_back(s1);
  a.s.push_back(s2);
  a.s.push_back(s3);

  return is;
}

ostream& operator <<(ostream& os, const Score &a)
{
  os << a.ID << "\t" << setprecision(3) << a.average << endl;
  
  return os;
}


int main()
{
    Score a;
    Score student[100];
    int count = 0;
    while(cin>>a)
    {
        if(a.ID/100000000 == 14 && (a.ID/1000)%100 == 12)
        {
          a.average = (2*a.s[0]+3*a.s[1]+4*a.s[2])*1.0/9.0;
          student[count++] = a; 
        }
        a.s.clear();
    }
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < count-i-1; j++)
        {
            if(student[j].average < student[j+1].average)
            {
                Score temp = student[j];
                student[j] = student[j+1];
                student[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < count; i++)
        cout << student[i];
    return 0;
}