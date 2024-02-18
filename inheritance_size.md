```c++
#include <iostream>

class A {
private:
    int a[100] = {0};   // 4 x 100 bytes
};

class B : public A {
private:
    int b[100] = {0};   // 4 x 100 bytes
};

class C : public B {
private:
    int c[100] = {0};   // 4 x 100 bytes
};

int main() {
    A a;
    B b;
    C c;
    std::cout << "A: " << sizeof(a) << " bytes" << '\n';
    std::cout << "B: " << sizeof(b) << " bytes" << '\n';
    std::cout << "C: " << sizeof(c) << " bytes" << '\n'; 
}

/* Output

A: 400 bytes
B: 800 bytes
C: 1200 bytes
*/
```