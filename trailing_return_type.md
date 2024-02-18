 ### Trailing return type (C++11)
```c++
int fun(int a, int b) { return a + b; }


// Trailing return type
auto fun(int a, int b) -> int { return a + b; }

// auto and decltype() : return type จะขึ้นอยู่กับ expression
auto fun(int a, int b) -> decltype(a + b) { return a + b; }

```
---
### auto and decltype
```c++
#include <iostream>
#include <typeinfo>
#include <type_traits>

template <typename T, typename U>
auto sum(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    std::cout << typeid(sum(5.5, 5.5)).name()    << '\n';  // double
    std::cout << typeid(sum(5.5, true)).name()   << '\n';  // double
    std::cout << typeid(sum(true, 5.5)).name()   << '\n';  // double
    std::cout << typeid(sum(true, false)).name() << '\n';  // int
}
```