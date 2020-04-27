/* int stack implementation using linked list 
no exception handling */
#include <iostream>
#include <cstddef>

const std::size_t STACK_MAX_SIZE = 100;

// linked list
struct Node {
    Node* next = nullptr;
    int num;
};

class Stack {
public:

    void push(int i);
    void pop();

    std::size_t size();
    bool empty();
    bool full() {return sz == STACK_MAX_SIZE ? true : false;}

private:
    Node head;
    std::size_t sz;
};

std::size_t Stack::size()
{
    
}
