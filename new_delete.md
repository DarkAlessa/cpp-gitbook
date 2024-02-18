## Memory leaks
```cpp
int* p = new int(7); // dynamically allocated int with value 7
p = nullptr; // memory leak
```

```cpp
void f()
{
    int* p = new int(7);
} // memory leak
```

```cpp
void f()
{
    int* p = new int(7);
    g();      // may throw
    delete p; // okay if no exception
} // memory leak if g() throws
```
---
### Example
```cpp
#include <iostream>

int main() {
    int* i = new int(1);
    int* j = new int(2);
    std::cout << "i :" << i << " : " << *i << '\n';
    std::cout << "j :" << j << " : " << *j << '\n';
    delete i; 
    delete j;
    std::cout << "----------------\n";
    i = new int(3);
    j = new int(4);
    std::cout << "i :" << i << " : " << *i << '\n';
    std::cout << "j :" << j << " : " << *j << '\n';
    delete i;
    delete j;
}

/* Output
i :0x68d2b0 : 1
j :0x68d2d0 : 2
----------------
i :0x68d2d0 : 3
j :0x68d2b0 : 4
*/
```