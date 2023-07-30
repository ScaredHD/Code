
template <typename T>
void f(T);

template <typename T>
void g(T&);

template <typename T>
const T& max(const T& a, const T& b);

/*
    template parameter has reference: no decays
    template parameter without reference: decays
*/

int main() {
    double arr[20];
    const int seven = 7;

    // Decay:
    //  1) array -> pointer
    //  2) function -> function pointer
    //  3) remove_cv(remove_reference(T))

    f(arr);  // T = double*     (decay: array -> pointer)
    g(arr);  // T = double[20]

    f(seven);  // T = int       (decay: const stripped)
    g(seven);  // T = const int&

    f(7);  // T = int
    // g(7);    // error: T = int, int& cannot be bound to prvalue

    // -------------------
    // error: T = 'const char[6]' and 'const char[4]' at the same time
    // No decay from string literal 'const char[]' to 'const char*'

    // max("apple", "pie");
}