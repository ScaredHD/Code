/* int stack implementation using linked list 
no exception handling */
#include <iostream>
#include <cstddef>

// const std::size_t STACK_MAX_SIZE = 100;

// linked list
struct Node {
    Node* next = nullptr;
    int num;
};

class Stack {
public:
    void push(int i);
    void pop();
    Node* prev(Node* p);

    std::size_t size();
    bool isEmpty();

private:
    Node* head = new Node();
    Node* tail = head;

};
inline
bool Stack::isEmpty()
{
    return head->next == nullptr ? true : false;
}

std::size_t Stack::size()
{
    std::size_t sz = 0;
    for (Node* p = head; p->next != nullptr; p = p->next)
    {
        sz++;
    }
    return sz;
}

inline
void Stack::push(int i)
{
    tail->num = i;
    tail->next = new Node();
    tail = tail->next;
}

inline
void Stack::pop()
{
    if (head == tail)
    {
        std::cout << "error: attempting to pop an empty stack" << std::endl;
    }
    else
    {
        delete tail;
        tail = prev(tail);
        tail->next = nullptr;
    }
}

Node* Stack::prev(Node* p)  // possible issue
{
    for (Node* ptr = head; ptr->next != nullptr; ptr = ptr->next)
    {
        if (ptr->next == p)
        {
            return ptr;
        }
    }
    return nullptr;
}



int main()
{
    Stack obj1;
    std::cout << obj1.size() << std::endl;
    obj1.push(3);
    obj1.push(4);
    obj1.push(5);
    std::cout << obj1.size() << std::endl;
    obj1.pop();
    std::cout << obj1.size() << std::endl;

    system("pause");
    return 0;
}
