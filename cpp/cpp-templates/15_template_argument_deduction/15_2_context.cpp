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

int main() {
    fppm(&X<33>::f);  // N = 33
}