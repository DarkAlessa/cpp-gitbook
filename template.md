## Variable Template
---
## Function Template
---
## Class Template
```c++
#include <iostream>
#include <string>

#define NL '\n'

template<class T>
struct OMG {
    static T func(T y) {
        return y;
    }
};

int main() {
    auto ss = OMG<std::string>::func("Hello world!");
    std::cout << ss << NL;

    auto va = OMG<int>::func(20);
    std::cout << va << NL;
}

/* Output
Hello world!
20
*/
```

```c++
#include <iostream>
#include <functional>

template<class T>
class Fn {
public:
    Fn() = default;
    Fn(auto&& a) : x(a) {}

    template<typename... U>
    int operator()(U... args) {
        return x(args...);
    }

private:
    std::function<T> x = nullptr;
};

int main() {
    Fn<int(int,int)> fn = [](int a, int b){ return a + b; };
    std::cout << fn(1, 2) << '\n';
    
    Fn<int(int,int,int)> fx = [](int a, int b, int c){ return a + b + c; };
    std::cout << fx(1, 2, 3) << '\n';
}

/* Output
3
6
*/
```
---
## Variadic Template
เทมเพลตที่มี `parameter pack` อย่างน้อยหนึ่งชุดเรียกว่า `vaiadic Template`

###	Template parameter pack
```c++
template<typename... Args>
void fn(Args... args) {
	/*...*/
}

/*
fn();
fn(int, int);
fn(float, int, double);
*/
```
### Perfect forwarding
```c++
#include <iostream>
#include <string>

template<typename... Args>
void printMe(Args&&... args) {
    (std::cout <<  ... <<  std::forward<Args>(args)) << '\n';
}

int main() {
    std::cout << '\n';
    printMe(1,2,3,4,5);	// 12345
    std::cout << '\n';
}

// Fold expressions //////////////////////////////////////////////
#include <iostream>
#include <string>

template<typename... Args>
auto sum(Args&&... values) {
    return (values + ...);
}

int main() {
    std::cout << sum(1,2,3);	// output = 6
}
```
---
## Template argument deduction
---
## Template Specialization
###	Explicit specialization
###	Partial specialization