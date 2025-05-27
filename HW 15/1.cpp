template<class Elem>
struct Link
{
    Link* prev; // previous link
    Link* next; // next link
    Elem val; // the value
};
//链表
template<class Elem> 
class List {
    Link<Elem>* first; // points to first element
    Link<Elem>* last; // points to one beyond last element
public:
    List() : first(new Link<Elem>()), last(first) {}
    Link<Elem>* begin(){ return first;}
    Link<Elem>* end(){ return last;}

    void push_front(const Elem& v){
        Link<Elem>* newLink = new Link<Elem>();
        newLink->val = v;
        newLink->next = first;
        newLink->prev = nullptr;
        if (first) first->prev = newLink;
        first = newLink;
        if (!last) last = newLink; // if list was empty, last points to the new element
    } // insert v at front
    void pop_front(){
        if (first == last) return; // empty list
        Link<Elem>* oldLink = first;
        first = first->next;
        if (first) first->prev = nullptr;
        delete oldLink; // remove the first element
    } // remove the first element
};
