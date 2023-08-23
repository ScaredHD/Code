#include <iostream>
#include <type_traits>
#include <typeinfo>

template <typename T>
void f(T) {
}

template <typename A>
void printParamterType(void (*)(A)) {
    std::cout << "Paramter type: " << typeid(A).name() << "\n";
    std::cout << "- is int:\t" << std::is_same<A, int>::value << "\n";
    std::cout << "- is const:\t" << std::is_const_v<A> << "\n";
    std::cout << "- is pointer:\t" << std::is_pointer_v<A> << "\n";
}


int main() {
    printParamterType(&f<int>);
    printParamterType(&f<const int>);
    printParamterType(&f<int[7]>);
    printParamterType(&f<int(int)>);
}