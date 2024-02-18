```cpp
#include <iostream>

auto main() -> int {
    int arr[5] = {1, 2, 3, 4, 5};
    int (&p)[5] = arr;

    std::cout << "size : " << sizeof(arr) << " / address : " << &arr << '\n';
    std::cout << "size : " << sizeof(p)   << " / address : " << &p   << '\n';
}
/* Output
size : 20 / address : 0x7fffe2e0b5c0
size : 20 / address : 0x7fffe2e0b5c0
*/
```