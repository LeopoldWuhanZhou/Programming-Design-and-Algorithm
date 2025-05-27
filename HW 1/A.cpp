#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int> v;
    for(int i=0; i<3; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < 2; i++) {
        cout << v[i] << ",";
    }
    cout << v[2] << endl;
    return 0;
}