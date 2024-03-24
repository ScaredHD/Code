# Notes on move semantics

## All one needs to understand perfect forwarding

### 1. Template argument deduction rules

```c++
template <typename T>
void f(T&& arg) {}
```

For universal reference `T&&`, when the expression of type `A` passed to `f` is:

* lvalue: `T` is `A&`
* xvalue: `T` is `A&&`
* prvalue: `T` is `A`

### 2. Reference collapsing rule

In short, lvalue reference(`&`) dominates. It's like logical AND operation with 0 being `&` and 1 being `&&`.

`T&`+`&` -> `T&`

`T&&`+`&` -> `T&`

`T&`+`&&` -> `T&`

`T&&`+`&&` -> `T&&`

### 3. Definition of `std::forward<>`

`std::forward<T>(t)` is equivalent to `static_cast<T&&>(t)`.

## Definitions of `std::forward<>` and `std::move`

`std::move` is essentially an unconditional cast to rvalue reference. And `std::forward<>` is a conditional cast to rvalue reference that only happens when forwarding rvalue arguments.

Return value of `std::move` looks like:

```c++
static_cast<std::remove_reference_t<T>&&>(t)
```

And return value of `std::forward` look like:

```c++
static_cast<T&&>(t)
```

Difference is that in `std::move` we have `remove_reference`, making cast-to type strictly an rvalue reference, whereas `std::forward` appends `&&` to `T`, resulting an rvalue refernce only when `T` is an rvalue refernce. Therefore `std::forward<T>(arg)` is a "conditional move":

* when passed argument is an lvalue: `T` is `A&`, and `std::forward<T>(arg)` is `A&`, same as `arg`
* when passed argument is an xvalue: `T` is `A&&`, and `std::forward<T>(arg)` is `A&&`, same as `std::move(arg)`
* when passed argument is an prvalue: `T` is `A`, and `std::forward<T>(arg)` is `A&&`, same as `std::move(arg)`
