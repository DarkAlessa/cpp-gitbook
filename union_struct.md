```c++
#include <iostream>

struct X { int a = 1, b = 2; };
union U
{
    X x;
    struct Y { int c = 3, d = 4, e = 5; };
    struct Z;   // forward declaration
};
struct U::Z { int m, n, o, p; };

int main() {
    std::cout << "sizeof(int)   : " << sizeof(int)  << "-byte" << '\n';
    std::cout << "sizeof(X)     : " << sizeof(X)    << "-byte" << '\n';
    std::cout << "sizeof(U::Z)  : " << sizeof(U::Z) << "-byte" << '\n';
    std::cout << "sizeof(U)     : " << sizeof(U)    << "-byte" << '\n';
    return 0;
}
```
Output
```
sizeof(int)   : 4-byte
sizeof(X)     : 8-byte
sizeof(U::Z)  : 16-byte
sizeof(U)     : 8-byte
```
