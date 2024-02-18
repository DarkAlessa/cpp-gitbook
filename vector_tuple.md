```cpp
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

int main() {
    std::vector<std::tuple<std::string, int>> blackpink;
    blackpink.push_back({"Lalisa Manoban", 25});
    blackpink.push_back({"Kim Jisoo"     , 27});
    blackpink.push_back({"Kim Jennie"    , 26});
    blackpink.push_back({"Roseanne Park" , 25});
    
    // Loop V.1 : iterator + std::tie()
    std::string name;
    int age;
    for(auto&& i : blackpink) {
        std::tie(name, age) = i;
        std::cout << name << " " << age << '\n';
    }
    
    std::cout << "-----------------" << '\n';
    
    // Loop V.2 : structure binding (since C++17)
    for (auto&& [name, age] : blackpink) {
        std::cout << name << " " << age << '\n';
    }
    
    std::cout << "-----------------" << '\n';
    
    // Loop V.3 : iterator + std::get
    for (auto&& i : blackpink) {
        std::cout << std::get<0>(i) << " " << std::get<1>(i) << '\n';
    }
}

/* Output

Lalisa Manoban 25
Kim Jisoo 27
Kim Jennie 26
Roseanne Park 25
-----------------
Lalisa Manoban 25
Kim Jisoo 27
Kim Jennie 26
Roseanne Park 25
-----------------
Lalisa Manoban 25
Kim Jisoo 27
Kim Jennie 26
Roseanne Park 25
*/
```