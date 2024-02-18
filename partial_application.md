```
keyword : Partial Application
ในวิทยาการคอมพิวเตอร์ partial application (หรือ partial function application) 
หมายถึงกระบวนการแก้ไขจำนวนอาร์กิวเมนต์ของฟังก์ชัน
f:(X x Y x Z) -> N ต้องการ fix หรือ bind อาร์กิวเมนต์แรก(X)จะได้
partial(f):(Y x Z) -> N

ให้ f(a,b,c) เป็นเป็นฟังก์ชั่น ที่มี 3 parameters
ต้องการให้ g เป็นฟังก์ชั่นที่มาจาก f แต่มี 2 parameters
g(a,b) := f(a, 4, b)
ฟังก์ชั่น g เรียกว่า Partial application
```

Example
```cpp
auto g = std::bind(f, _1, 4, _2);	// _1, _2 คือ placeholders
```

```cpp
#include <iostream>
#include <string>
#include <functional>

void f1(int a, int b, int c) {
    std::cout << a << ", " << b << ", " << c << '\n';
}

int main() {
    using namespace std::placeholders; // for _1, _2, _3...

    auto fa = std::bind(fn, _3, _2, _1); // fa(int c, int b, int a)
    fa(1, 2, 3);

    auto fb = std::bind(fn, _1, _2, 3); // fb(int a, int b, int c = 3)
    fb(1, 2);

    auto fd = std::bind(fn, _1, 2, _2); // fb(int a, int b = 2, int c = 3)
    fd(1,3);

    // ถ้าไม่ใช้ _2 🤔
    auto fc = std::bind(fn, _1, 2, _3); // fb(int a, int b = 2, int c)
    fc(1, 2, 3); // 2 is unused
    // fc(1,3);  // error
}

/*
3, 2, 1
1, 2, 3
1, 2, 3
1, 2, 3
*/
```

```cpp
#include <iostream>
#include <functional>
using namespace std::placeholders;

void fn(int a, int b) {
    std::cout << (a + b) << '\n';
}

int main() {    
    auto x = std::bind(fn, _1, _2);
    x(10, 20);  // 30
    
    // ใช้ std::bind พร้อม arguments
    std::bind(fn, _1, _2)(10, 20); // 30
}
```
