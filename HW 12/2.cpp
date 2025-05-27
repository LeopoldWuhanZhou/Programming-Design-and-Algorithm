#include <iostream>
using namespace std;
void test() {
    int cnt = 0;
    while (1) {
        int *p = new int[1024 * 1024];
        cnt++;
        cout << cnt << endl;
    }
}
int main() {
    test();
    return 0;
}