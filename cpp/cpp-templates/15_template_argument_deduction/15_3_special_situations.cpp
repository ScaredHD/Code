template <typename T>
void f(T, T);

int main() {
    void (*pf)(char, char) = &f;
}