#include <iostream>
#include <string>
using namespace std;

template <class T>
void my_swap(T& a, T& b) //实现交换任意类型的两个变量值
{
    //在此处添加你的代码
    T temp = a;
    a = b; 
    b = temp;    
    return;
}

//测试代码，请不要修改
int main()
{

    int a, b;
    cin >> a >> b;
    my_swap(a, b);
    cout << a << " " << b << endl;

    double x, y;
    cin >> x >> y;
    my_swap(x, y);
    cout << x << " " << y << endl;

    string s1, s2;
    cin >> s1 >> s2;
    my_swap(s1, s2);
    cout << s1 << " " << s2 << endl;

    return 0;
}