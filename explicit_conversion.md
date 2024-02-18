```
Implicit Conversion การแปลงโดยนัย
Explicit Conversion การแปลงแบบชัดเจน

    int _implicit = 4.5;	  // copy-initialization // implicit conversion 
    int _explicit = int(4.5); // explicit conversion
    int _explicit = (int)4.5; // explicit conversion
    int _x(10);		          // direct initialization

explicit keyword คือ การอนุญาตให้ใช้ explicit conversion หรือ Direct initialization เท่านั้น ไม่อนุญาตให้ใช้กับ implicit conversion และ copy-initialization
```
```cpp
class A {
public:
   A();
   A(int x) : x(x) {};
   A(const char* s) : s(s) {};
private:
    int x;
    string s;
};

int main() {
    A a1 = 1;		// ✔copy-initialization
    A a2 = "Elsa";	// ✔copy-initialization
    A a3 = A(1);	// ✔explicit conversion
    A a4(2);		// ✔direct initialization
    A a5("Alice");	// ✔direct initialization
}
```
```cpp
class A {
public:
   explicit A();
   explicit A(int x) : x(x) {};
   explicit A(const char* s) : s(s) {};
private:
    int x;
    string s;
};

int main() {
    A a1;
    A a2 = A(1);
    A a3(1);
    A a4 = A("Elsa");
    A* p = new A(1);
    A a5 = (A)1;
    A a6 = static_cast<A>(1);
    A a7 = 10;		    // ❌copy-initialization
    A a8 = "Alessa";	// ❌copy-initialization
}
```
```cpp
#include <iostream>

class A {
public:
    explicit A(int i, int j): i(i), j(j){}
    void print() { std::cout << i << " " << j << '\n'; }
private:
    int i = 0;
    int j = 0;
};

int main() {
    A a = A{10, 20};    // ✔explicit conversion
//  A a = (A){10, 20};  // warning: ISO C++ forbids compound-literals [-Wpedantic]
    a.print();          // 10, 20
}
```