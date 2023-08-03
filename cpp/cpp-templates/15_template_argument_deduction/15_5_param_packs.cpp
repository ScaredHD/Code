
template <typename First, typename... Rest>
void f(First first, Rest... rest);

void g(int i, double j, int* k) {
    f(i, j, k);  // First = int, Rest = {double, int*}
}

// ---------------------------------

template <typename T, typename U>
class pair {};

template <typename T, typename... Rest>
void h1(const pair<T, Rest>&...);
// expands to: 'const pair<T, Rest1>&, const pair<T, Rest2>&, ...'

template <typename... Ts, typename... Rest>
void h2(const pair<Ts, Rest>&...);
// expands to : 'const pair<Ts1, Rest1>&, const pair<Ts2, Rest2>&, ...'

void foo(pair<int, float> pif, pair<int, double> pid, pair<double, double> pdd) {
    h1(pif, pid);  // T = int, Rest = {float, double}
    h2(pif, pid);  // Ts = {int, int}, Rest = {float, double}
    // h1(pif, pdd);  // ERROR: T = int and double
    h2(pif, pdd);  // T = {int, double}, Rest = {float, double}
}

// ---------------------------------

template <typename... Types>
class Tuple {};

template <typename... Types>
bool f1(Tuple<Types...>, Tuple<Types...>);

template <typename... Types1, typename... Types2>
bool f2(Tuple<Types1...>, Tuple<Types2...>);

void bar(Tuple<short, int, long> sv, Tuple<unsigned short, unsigned, unsigned long> uv) {
    f1(sv, sv);  // Types = {short, int, long}
    f2(sv, sv);  // Types1 = {short, int, long}
                 // Types2 = {short, int, long}

    // f1(sv, uv); //ERROR: Types = {short, int, long} for 1-st argument
    // Types = {unsigned short, unsigned, unsigned long} for 2-nd argument

    f2(sv, uv);  // Types1 = {short, int, long}
                 // Types2 = {unsigned short, unsigned, unsigned long}
}
