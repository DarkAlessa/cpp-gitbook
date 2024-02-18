```cpp
#include <iostream>
#include <typeinfo>

struct A {
    int x = 10;
};

int main() {
    int A::*a = &A::x;
    auto b = &A::x;
    static_assert(typeid(a) == typeid(&A::x));
    std::cout << typeid(a).name()     << "\n";
    std::cout << typeid(b).name()     << "\n";
    std::cout << typeid(&A::x).name() << "\n";
}
```
output
```console
M1Ai
M1Ai
M1Ai
```