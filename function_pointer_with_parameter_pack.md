```cpp
#include <iostream>
#include <string>
#include <tuple>

// Parameter pack
template<typename T, typename... Ts>
T (*fp)(Ts... args) = nullptr;  // function pointer

// Function template
template<typename... Args>
auto fn(Args... values) {
    return (values + ...);
}

using STUDENT = std::tuple<std::string, int, int>;
STUDENT f_c(std::string&& ss, int a, int b) {
    return {ss, a, b};
} 

int main() {

    fp<int, int, int> = fn;
    std::cout << fp<int, int, int>(10, 10) << '\n';

    fp<float, float, float> = fn;
    std::cout << fp<float, float, float>(1.45f, 2.67f) << '\n';

    fp<STUDENT, std::string&&, int, int> = f_c;
    auto x = fp<STUDENT, std::string&&, int, int>("Alice", 25, 1002);
    std::cout << std::get<0>(x) << ", " << std::get<1>(x) << ", " << std::get<2>(x) << '\n';
}
/*
Output

20
4.12
Alice, 25, 1002
*/
```
