
template <typename T>
struct RemoveReferenceT {
    using Type = T;
};

template <typename T>
struct RemoveReferenceT<T&> {
    using Type = T;
};

template <typename T>
struct RemoveReferenceT<T&&> {
    using Type = T;
};

int main() {
    RemoveReferenceT<int>::Type t1;       // int
    RemoveReferenceT<int&>::Type t2;      // int
    RemoveReferenceT<double&&>::Type t3;  // double
}
