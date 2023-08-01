#include <initializer_list>

template <typename T>
void f(T p);

template <typename T>
void f2(std::initializer_list<T>);

int main() {
    // f({1, 2, 3});   // ERROR: cannot decuce T from braced-init-list

    f2({2, 3, 5, 7, 9});  // T = int
    // f2({'a', 'e', 'i', 'o', 'u', 42});  // ERROR : T = char and int
}