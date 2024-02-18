```cpp
#include <iostream>

struct X {
    enum { One = 1 };
    enum Y{ Two = 2 };
};

int main() {
    X x;
    std::cout << X::One << '\n';
    std::cout << x.One << '\n';
    std::cout << X::Y::Two << '\n';
    std::cout << x.Y::Two << '\n';
    std::cout << x.Two << '\n';
}

/* Output
1
1
2
2
2
*/
```