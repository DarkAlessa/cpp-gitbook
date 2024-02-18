```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 10;
    
    auto a = [](int x, int y) -> int { return x * y; };
    auto b = [&]() -> int { return x * y; }();
    
    std::cout << a(10,10) << '\n';
    std::cout << b << '\n';
}
/* Output
100
100
*/
```

```cpp
#include <iostream>

int main() {
    auto a = []() -> int* { return new int(10); };
    auto b = []() -> int* { return new int(20); }();
    std::cout << *a() << '\n';
    std::cout << *b << '\n';
}
/* Output
10
20
*/
```
