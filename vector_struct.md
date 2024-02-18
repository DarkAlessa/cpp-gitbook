```cpp
#include <iostream>
#include <vector>

struct BLACKPINK {
    std::string name;
    int age;
};

int main(){
    std::vector<BLACKPINK> member;
    member.push_back({"Lalisa Manoban", 24});
    member.push_back({"Roseanne Park",  25});
    member.push_back({"Kim Jennie",     26});
    member.push_back({"Kim Jisoo",      27});
    /*
    std::cout << member[0].name << ", " << member[0].age << std::endl;
    std::cout << member.at(0).name << ", " << member.at(0).age << std::endl;
    */
    for (const auto& index : member) {
        std::cout << index.name << ", " << index.age << std::endl;
    }
    return 0;
}
```