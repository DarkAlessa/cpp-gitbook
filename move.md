`std::move` คือการแปล lvalue เป็น rvalue

```cpp
    std::string s1 = "Move";
//  std::string&& s2 = s1;             // error: cannot bind rvalue reference (s1 คือ lvalue)
    std::string&& s2 = std::move(s1);  // xvalue 🤔
```

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <utility> // std::move()
#include <iomanip> // std::quoted()


int main() {
    std::string s1 = "Hello";
    std::string m1 = std::move(s1);
    // หลังจาก move, s1 อยู่ในสถานะ "valid แต่ unspecified" (valid but unspecified state)
    // m1 เป็นเจ้าของ (owner) ของ "Hello"
    std::cout << &s1 << " : " << std::quoted(s1) << '\n';
    std::cout << &m1 << " : " << std::quoted(m1) << '\n';

    std::cout << "------------------------\n";

    std::string   s2 = "Hello";
    std::string&& m2 = std::move(s2);

    std::cout << &s2 << " : " << std::quoted(s2) << '\n';
    std::cout << &m2 << " : " << std::quoted(m2) << '\n';

    std::cout << "------------------------\n";

    std::string s3 = "Vector";
    std::cout << "Before : " << std::quoted(s3) << '\n';
    std::vector<std::string> vs;
    vs.push_back(std::move(s3));
    std::cout << "After  : " << std::quoted(s3) << '\n';
}
/* Output
0x7ffda3b1e7f0 : ""
0x7ffda3b1e7d0 : "Hello"
------------------------
0x7ffda3b1e7b0 : "Hello"
0x7ffda3b1e7b0 : "Hello"
------------------------
Before : "Vector"
After  : ""
*/
```