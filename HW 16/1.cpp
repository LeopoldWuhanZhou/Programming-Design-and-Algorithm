#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> cnt;
    string s, word;
    getline(cin, s);
    for (int i=0; i < s.size(); i++) {
        if ((s[i] >='A' && s[i] <= 'Z')||(s[i] >='a' && s[i] <= 'z')) 
            word += s[i];
        else {
            if (!word.empty()) {
                cnt[word]++;
                word.clear();
            }
        }
    }
    for (auto &p : cnt)
        cout << p.first << " " << p.second << endl;
    return 0;
}