#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    while(cin >> a)
    {
        int res = 0;
        if(a.length() > 2 && a[0] == '0' && a[1] == 'x'){
            for(int i = 2; i < a.length(); i++){
                if(a[i] >= '0' && a[i] <= '9'){
                    res = res * 16 + a[i] - '0';
                }else if(a[i] >= 'A' && a[i] <= 'F'){
                    res = res * 16 + a[i] - 'A' + 10;
                }else if(a[i] >= 'a' && a[i] <= 'f'){
                    res = res * 16 + a[i] - 'a' + 10;
                }
            }
        }
        else if(a[0]=='0'){
            for(int i = 1; i < a.length(); i++){
                res = res * 8 + a[i] - '0';
            }
        }
        else{
            for(int i = 0; i < a.length(); i++){
                res = res * 10 + a[i] - '0';
            }
        }
        cout << res << endl;
    }
    return 0;
}