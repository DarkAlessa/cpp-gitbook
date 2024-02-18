## std::list
```cpp
#include <iostream>
#include <list>

auto main() -> int {
    std::list<int> list = {0, 0, 0, 0, 0};
    auto it = list.begin();
    std::advance(it, 2);
    list.emplace(it, 100);

    for (auto& i : list) {
        std::cout << i << ' ';
    }
}

/* output
 0 0 100 0 0 0
*/

```
```cpp
#include <iostream>
#include <list>

auto main() -> int {
    std::list<int> list = {0, 0, 0, 0, 0};
    auto it = list.begin();
    std::advance(it, 2);
    list.emplace(it, *it + 20);

    for (auto& i : list) {
        std::cout << i << ' ';
    }
}

/* output
 0 0 20 0 0 0
*/

```
```cpp
#include <iostream>
#include <list>

auto main() -> int {
    std::list<int> list = {0, 0, 0, 0, 0};
    auto it = list.begin();
    std::advance(it, 2);
    *it += 50;

    for (auto& i : list) {
        std::cout << i << ' ';
    }
}

/* output
 0 0 50 0 0
*/

```