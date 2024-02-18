```cpp
#include <iostream>

int main() {
    for (const char* ss : {"Lisa", "Patty", "Alice", "Elsa"}) {
        std::cout << ss << '\n';
    }
}

/* Output
Lisa
Patty
Alice
Elsa
*/
```