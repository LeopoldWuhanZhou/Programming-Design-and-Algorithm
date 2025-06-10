#include <iostream>
#include <fstream> 
using namespace std;

template<class Elem>
struct Link {
    Link* prev;    // 指向前一个节点
    Link* next;    // 指向后一个节点
    Elem  val;     // 数据元素的值
    Link(const Elem& v = Elem(), Link* p = 0, Link* n = 0) : val(v), prev(p), next(n) {}
};

template<class Elem>
class List {
    Link<Elem>* first;   // 指向链表中的第一个节点
    Link<Elem>* last;    // 指向链表中最后一个节点之后的位置
public:
    List() : first(new Link<Elem>()), last(first) {}
    ~List();

    Link<Elem>* begin(){ return first; }
    Link<Elem>* end()  { return last; }

    void push_back(const Elem& v);  // 向链表的尾部追加一个值为v的节点
    void pop_back();                // 从链表尾部弹出一个节点
};

template<class Elem>
List<Elem>::~List( ) // 析构函数
{
    Link<Elem>* p = begin();
    for ( Link<Elem>* p = begin(); p != end(); p = p->next )
        pop_back();
}

template<class Elem>
void print(List<Elem>& List)
{
    Link<Elem>* p = List.begin();
    while (p != List.end())
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

template<class Elem>
void reverse_print(List<Elem>& List)
{
    Link<Elem>* p = List.end()->prev;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->prev;
    }
    cout << endl;
}

template<class Elem>
void List<Elem>::push_back(const Elem& v) // 向链表的尾部追加一个值为v的节点
{
    if(first->next == nullptr) 
    {
        first = new Link<Elem>(v, nullptr, last);
        first->next = last;
        last->prev = first;
        return;
    }
    else
    {
        Link<Elem>* p = last->prev;
        Link<Elem>* newNode = new Link<Elem>(v, p, last);
        p->next = newNode; 
        last->prev = newNode; 
        if(first->next == nullptr) first->next = newNode;
    }
}

template<class Elem>
void List<Elem>::pop_back() // 从链表尾部弹出一个节点
{
    Link<Elem>* p = last->prev;
    if (p == first) {
        delete p; 
        first->next = nullptr;
        last = first;
    } else {
        p->prev->next = last; 
        last->prev = p->prev; 
        delete p; 
    }
    if (last->prev == nullptr) { 
        first->next = nullptr; 
        last = first; 
    }
    return;
}

//测试代码，请不要修改
int main()
{
    List<int> List;
    for (int n; cin >> n;)
    {
        List.push_back(n);
        print(List);          //正向打印链表中的数据元素
        reverse_print(List);  //逆向打印链表中的数据元素
    }

    while (List.begin() != List.end())
    {
        List.pop_back();
        print(List);          //正向打印链表中的数据元素
        reverse_print(List);  //逆向打印链表中的数据元素
    }
    
    return 0;
}