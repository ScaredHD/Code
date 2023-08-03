#include <type_traits>
#include <utility>
#include <iostream>

using RCI = const int&;
volatile RCI&& r = 42;  // r has type 'const int&'

using RRI = int&&;
const RRI&& rr = 42;  // rr has type 'int&&'

// ----------------------------

template <typename T>
void f(T&& p) {
    // T x;  // if passed lvalue, T will be lvalue reference type, which can not be uninitialized

    // std::remove_reference_t<T> x;    // x will never be reference
}

void g() {
    int i;            // lvalue
    const int j = 0;  // lvalue

    f(i);  // T = int&, paramType = int&    ( by reference collapsing)

    f(j);  // T = const int&, paramType = const int&    (by reference collapsing)

    f(2);  // T = int, paramType = int&&
}

// Perfect forwarding ------------------------------------

class C {};

void g(C&) {
    std::cout << "g(C&)\n";
}

void g(const C&) {
    std::cout << "g(const C&)\n";
}

void g(C&&) {
    std::cout << "g(C&&)\n";
}

template <typename T>
void notPerfect(T&& x) {
    g(x);
}

template <typename T>
void forwardToG(T&& x) {
    g(std::forward<T>(x));  // same as g(static_cast<T&&>(x));
}

void foo() {
    C v;
    const C c;

    forwardToG(v);             // T = 'C&',          T&& = 'C&',         calls g(C&)
    forwardToG(c);             // T = 'const C&',    T&& = 'const C&',   calls g(const C&)
    forwardToG(C());           // T = 'C',           T&& = 'C&&',        calls g(C&&)
    forwardToG(std::move(v));  // T = 'C'            T&& = 'C&&',        calls g(C&&)

    notPerfect(v);             // T = 'C&',          T&& = 'C&',         calls g(C&)
    notPerfect(c);             // T = 'const C&',    T&& = 'const C&',   calls g(const C&)
    notPerfect(C());           // T = 'C',           T&& = 'C&&',        calls g(C&)  (not perfect)
    notPerfect(std::move(v));  // T = 'C'            T&& = 'C&&',        calls g(C&)  (not perfect)
}

int main() {
    foo();
}