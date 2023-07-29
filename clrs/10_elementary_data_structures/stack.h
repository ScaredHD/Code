#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>

template <typename T, size_t N = 1000>
class Stack {
  public:
    Stack() = default;
    Stack(std::initializer_list<T> il) {
        for (const auto& x : il) push(x);
    }

    bool empty() const { return size() == 0; }
    size_t size() const { return stackSize; }
    T top() const { return arr[stackSize - 1]; }

    void push(T x) {
        if (stackSize == N) std::cerr << "overflow\n";
        arr[stackSize++] = x;
    }
    void pop() {
        if (stackSize == 0) std::cerr << "underflow\n";
        --stackSize;
    }

    T* data() { return arr; }
    const T* data() const { return arr; }

  private:
    size_t stackSize{};
    T arr[N];
};

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const Stack<T, N>& s) {
    for (int i = 0; i < s.size(); ++i) {
        os << s.data()[i] << (i == s.size() - 1 ? "" : ",");
    }
    return os;
}