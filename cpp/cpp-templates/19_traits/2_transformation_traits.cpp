
// Removing references
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

// Adding references
template <typename T>
struct AddLValueRefT {
    using Type = T&;
};

template <typename T>
using AddLValueRef = typename AddLValueRefT<T>::Type;

template <typename T>
struct AddRValueRefT {
    using Type = T&&;
};

template <typename T>
using AddRValueRef = typename AddRValueRefT<T>::Type; 


int main() {
    RemoveReferenceT<int>::Type t1;       // int
    RemoveReferenceT<int&>::Type t2;      // int
    RemoveReferenceT<double&&>::Type t3;  // double
}
