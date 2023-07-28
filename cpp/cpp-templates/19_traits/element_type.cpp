#include <vector>
#include <list>
#include <iostream>

// 19.3.1 Element Types (p.401)

template <typename Container>
struct ElementT {
    using Type = typename Container::value_type;
};

template <typename T>
struct ElementT<std::vector<T>> {
    using Type = T;
};

template <typename T>
struct ElementT<std::list<T>> {
    using Type = T;
};

template <typename T, size_t N>
struct ElementT<T[N]> {
    using Type = T;
};

template <typename T>
struct ElementT<T[]> {
    using Type = T;
};

template <typename T>
void printElementType(const T& c) {
    std::cout << "Container of " << typeid(typename ElementT<T>::Type).name() << " elements.\n";
}

int main() {
    std::vector<bool> s;
    printElementType(s);

    int arr[42];
    printElementType(arr);

    std::list<double> l;
    printElementType(l);
}