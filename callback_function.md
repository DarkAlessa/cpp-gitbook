```text
Callback function คือฟังก์ชั่นที่ใช้ parameter เป็นฟังก์ชั่นอื่น
รูปแบบที่พบบ่อยคือ
callback_fn(x, function);
callback_fn(x, y, funciton);
เช่น 
std::vector<..> v {...};
auto print = [](..){...};
std::for_each(v.begin(), v.end(), print); // 👈
```
```cpp
#include <iostream>
#include <functional>

int fn(int a, int b) { 
    return a + b; 
}

// Function Pointer 
int callback_1(int a, int b, int(*fp)(int, int)) { 
    return fp(a, b); 
}

// Function Object
int callback_2(std::function<int(int,int)>&& fx) {
    return fx(0, 0);
}

int main() {    
    /*
    Function pointer ใช้กับ std::bind ไม่ได้
    แต่ใช้ได้กับ Lambda expression
    */
    std::cout << callback_1(10, 90, fn) << '\n';    // 100
    std::cout << callback_1(10, 90, [](int, int){ return fn(2, 4); }) << '\n';  // 6
    // สังเกตว่าถ้าใช้ lambda เอาท์พุตจะเป็น 6 แทนที่จะเป็น 100 🤔
    
    std::cout << "---" << '\n';

    /*
    Function object สามารถใช้กับ std::bind ได้เพราะ std::bind รีเทิร์นค่าเป็น function object
    */
    std::cout << callback_2(std::bind(fn, 10, 90)) << '\n';
    std::cout << callback_2([](int,int){ return fn(10, 90); }) << '\n';
}
```