Tuple : เป็นอ็อบเจกต์ที่สามารถเก็บคอลเล็กชันขององค์ประกอบได้ แต่ละองค์ประกอบสามารถเป็นประเภทที่แตกต่างกัน
ตัวอย่าง tuple [1,2,3], [x, y, z]

EX1
```cpp
#include <iostream>
#include <tuple>

std::tuple<int, double> f(int a, double b) {
    return std::make_tuple(a, b);		        // OK
    // return std::tuple<int, double>(a, b);    // OK
    // return {a, b}; // Error until N4387 (applied as a defect report for C++11)
}

int main()
{
    int x1;
    double y1;

    // std::tie() ใช้เพื่อแกะ(unpack) Tuple
    std::tie(x1, y1) = f(10, 2.54);
    std::cout << x1 << " " << y1 << '\n';

    // structure binding : since C++17
    auto [x2, y2] = f(20, 4.89);
    std::cout << x2 << " " << y2 << '\n';
}

/* Output
10 2.54
20 4.89
*/
```

EX2
```cpp
#include <iostream>

struct X {
    int a = 10;
    int b = 20;
};

int main() {
    X x;
    auto& [m, n] = x;	// structure binding since C++17
    std::cout << "m = " << m << '\n';
    std::cout << "n = " << n << '\n';
}

/* Output
m = 10
n = 20
*/
```