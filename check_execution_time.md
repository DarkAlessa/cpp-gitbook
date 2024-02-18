```c++
#include <iostream>
#include <chrono>
using namespace std::chrono;

int main() {
    int i = 3;
    auto start = high_resolution_clock::now();
    // Code here
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    std::cout << duration.count() << '\n';
}
```