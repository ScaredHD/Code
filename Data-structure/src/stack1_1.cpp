/* int stack implementation using array 
no exception handling */
#include <iostream>
#include <cstddef>
using std::cin;
using std::cout;
using std::endl;

const size_t STACK_MAX_SIZE = 100;


class Stack {
public:
    Stack(): top(arr), bottom(arr) {}

    void push(int i);
    void pop();
    size_t size();             // stack size
    bool empty();
    bool full();

    void print();              // print on screen

private:
    int* top = nullptr;        // stack top, pass-the-end pointer of arr
    int* bottom = nullptr;     // stack bottom, beginning of arr
    int arr[STACK_MAX_SIZE];
};

inline size_t Stack::size()
{
    return top - bottom;    // notion: no +1 (pass-the-end)
}

inline bool Stack::empty()
{
    return size() ? false : true;
}

inline bool Stack::full()
{
    return size() == STACK_MAX_SIZE ? true : false;
}


inline void Stack::pop()
{
    if (!empty())
    {
        top--;
    }
    else
    {
        cout << "error: attempting to pop an empty stack" << endl;
    }
}

inline void Stack::push(int i)
{
    if (!full())
    {
        *top++ = i;     // *top = i; top++
    }
    else
    {
        cout << "error: attempting to push into a full stack" << endl;
    }
}

inline void Stack::print()
{
    for (auto p = bottom; p != top; p++)
    {
        cout << *p << " ";
    }
}

int main()
{
    Stack s1;

    for (int i = 0; i != 104; i++)
    {
        s1.push(1);
    }

    s1.print();


    system("pause");
    return 0;
}