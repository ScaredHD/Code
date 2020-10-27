#include <iostream>

using std::cout;
using std::endl;

template <typename T>
struct Node
{
    T data;
    Node* next = nullptr;
};

template <typename T>
class List {
public:
    void display() const;   // display all nodes of linked list
    inline bool isEmpty() const { return (head == tail) ? true : false; }
    inline size_t size() const { return sz; } // return size of linked list (head node not included)

    // for debugging
    Node<T>* getTail() const { return tail; }
    Node<T>* getCurPtr() const { return curPtr; }
    size_t getCurPos() const { return curPos; }

    inline void pushBack(T elem);  // insert an element with value elem at the end of list
    Node<T>* prev(Node<T>* ptr);    // return pointer to the node preceding the one ptr points to
    Node<T>* prev() { return prev(curPtr); }    // prev(curPtr)
    inline bool popBack();     // delete the last element of list, return false if list is empty

    Node<T>* insert(Node<T>* p, T elem);    // insert node with data value elem to where p points to

private:
    Node<T>* head = new Node<T>;
    Node<T>* tail = head;
    Node<T>* curPtr = head;    // pointer to currently modified position
    size_t curPos = 0;         // index of currently modified position
    size_t sz = 0;             // size of list

    void resetCurPos(); // reset curPos to where curPtr points to
};


int main()
{
    List<int> ls;
    ls.pushBack(3);
    ls.pushBack(5);
    ls.display();

    auto p = ls.prev(ls.getTail());

    ls.insert(p, 42);
    ls.display();


    system("pause");
    return 0;
}

template <typename T>
void List<T>::resetCurPos()
{
    Node<T>* p = head;
    size_t idx = 0;
    while (p != curPtr)
    {
        p = p->next;
        idx++;
    }
    curPos = idx;
}

template <typename T>
void List<T>::display() const
{
    Node<T>* p = head;
    size_t idx = 0;
    for (; p != tail; p = p->next, idx++)
    {
        cout << "#" << idx << ":\t" << p->data << "\t" << p->next << endl;
    }
    cout << "#" << idx << ":\t" << p->data << "\t" << p->next << endl << endl;
}

template <typename T>
void List<T>::pushBack(T elem)
{
    // creating a new node, connecting to the tail
    tail->next = new Node<T>;

    // update tail and fill new tail with elem
    tail = tail->next;
    tail->data = elem;

    // update current status
    sz++;
    curPtr = tail;
    resetCurPos();
}

template <typename T>
Node<T>* List<T>::prev(Node<T>* ptr)
{
    Node<T>* p = head;
    while (p->next != ptr) { p = p->next; }
    return p;
}

template <typename T>
bool List<T>::popBack() 
{
    // if empty, return false and do nothing
    if (isEmpty()) { return false; }

    // relocate tail
    tail = prev(tail);
    // delete popped node
    delete tail->next;
    // reset tail node's next address to nullptr
    tail->next = nullptr;

    // update current status
    sz--;
    curPtr = tail;
    resetCurPos();
}

template <typename T>
Node<T>* List<T>::insert(Node<T>* p, T elem)
{
    Node<T>* ptr = new Node<T>;
    ptr->data = elem;
    ptr->next = p;
    p = prev(p);
    p->next = ptr;

    // update current status
    sz++;
    curPtr = p;
    resetCurPos();
    return curPtr;
}




