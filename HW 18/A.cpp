#include<iostream>
#include<vector>
using namespace std;
int maxv(const vector<int>& v)
{
    int max_value = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > max_value) {
            max_value = v[i];
        }
    }
    return max_value;
}
int main()
{
    int a;
    vector<int> v;
    while(cin >> a)
    {
        v.push_back(a);
    }
    cout<< maxv(v) << endl;
    return 0;
}