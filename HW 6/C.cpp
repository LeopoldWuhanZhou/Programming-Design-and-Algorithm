#include<iostream>
#include<string>
using namespace std;
class RomanInt{
public:
    string roman;
    int as_int() {
        int sum=0;
        for (int i = 0; i < roman.size(); ++i) {
            if (roman[i] == 'M') sum += 1000;
            else if (roman[i] == 'D') sum += 500;
            else if (roman[i] == 'C') {
                if (i + 1 < roman.size() && (roman[i + 1] == 'D' || roman[i + 1] == 'M'))
                    sum -= 100;
                else
                    sum += 100;
            }
            else if (roman[i] == 'L') sum += 50;
            else if (roman[i] == 'X') {
                if (i + 1 < roman.size() && (roman[i + 1] == 'L' || roman[i + 1] == 'C'))
                    sum -= 10;
                else
                    sum += 10;
            }
            else if (roman[i] == 'V') sum += 5;
            else if (roman[i] == 'I') {
                if (i + 1 < roman.size() && (roman[i + 1] == 'V' || roman[i + 1] == 'X'))
                    sum -= 1;
                else
                    sum += 1;
            }
        }
        return sum;
    }
};
istream& operator>>(istream& is, RomanInt& r)
{
    is>>r.roman;
    return is;
}
int main()
{
    RomanInt a,b;
    cin>>a>>b;
    cout<<a.as_int()+b.as_int()<<endl;
    return 0;
}