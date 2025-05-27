#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
    int sum = 0;
    for(a = 1; a <=19; a++)
        for(b = 1; b <= (100-5*a)/2; b++)
            if (100 != (5*a + 2*b)) sum++;
    cout << sum << endl;
    return 0;
}