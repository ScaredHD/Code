template <typename T>
void f0(T);

template <typename T>
void f1(T*);

template <typename E, int N>
void f2(E (&)[N]);

template <typename T1, typename T2, typename T3>
void f3(T1 (T2::*)(T3*));

class S {
  public:
    void f(double*);
};

void g(int*** ppp) {
    bool b[42];

    f1(ppp);  // T = int**

    f2(b);  // E = bool, N = 42

    f3(&S::f);  // T1 = void, T2 = S, T3 = double
}

template <int N>
class X {
  public:
    using I = int;
    void f(int) {}
};

template <int N>
void fppm(void (X<N>::*p)(typename X<N>::I));

template <typename T>
struct A {};

template <>
struct A<int> {
    using Type = double;
};

template <>
struct A<char> {
    using Type = double;
};

template <typename T>
void ndc(typename A<T>::Type x);

int main() {
    fppm(&X<33>::f);  // N = 33

    // ndc(3.14);
    
    // ERROR: 'A<T>::Type' is non-deduced context
    // Cannot deduce 'T' from member of 'A<T>'. They have no relationship
    // (because we can have specialization)
}