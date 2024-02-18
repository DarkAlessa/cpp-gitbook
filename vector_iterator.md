```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> x{0, 1, 2, 3, 4, 5};
    std::vector<int>::iterator i;
    i = x.begin();
    x.erase(i+1);
    for (auto i = x.begin(); i != x.end(); ++i) {
        std::cout << ' ' << *i;
    }
}
```
```cpp
#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> x{1, 2, 3, 4, 5, 6};
    for (auto i = x.begin(); i != x.end(); ++i) {
        if (*i == 5) {
            x.erase(i);
        }
    }

    for (auto i = x.begin(); i != x.end(); ++i) {
        std::cout << ' ' << *i;
    }
}
```