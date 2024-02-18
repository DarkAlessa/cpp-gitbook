## Copy constructors & Copy assignment
```cpp
    // Copy Constructors
    A(const A& arg) : member(arg.member) {}

    // Copy Assignment
    A& operator=(const A& other) {
         member = other.member;
         return *this;
    }
```

Example
```cpp
#include <iostream>
#include <string>
#include <utility>

struct X{
    X() = default;
    X(int a, int b) : a(a), b(b) {}

    // Copy constructor
    X(const X& o) : a(o.a), b(o.b) {
        std::cout << "Copy constructor" << '\n';
    }

    // Copy assignment
    X& operator=(const X& o) {
        std::cout << "Copy assignment" << '\n';
        a = o.a;
        b = o.b;
        return *this;
    }

    void get() { std::cout << a << ' ' << b << '\n'; }
private:
    int a = 0;
    int b = 0;
};

int main() {
    X x1(10, 20);

    X x2(x1);    // Copy constructor
    X x3 = x1;   // Copy constructor
    X x4;
    x4 = x1;     // Copy assignment
    
    x2.get();
    x3.get();
    x4.get();
}
```
---

## Move Constructors & Move Assignment

```cpp
    // Move Constructors
    A(A&& arg) : member(std::move(arg.member)) {}

    // Move Assignment
    A& operator=(A&& other) {
         member = std::move(other.member);
         return *this;
    }
```

Example
```cpp
#include <iostream>
#include <string>
#include <utility>

struct X {
    X() = default;
    X(int a, int b) : a(a), b(b) {}

    // Move constructor
    X(X&& o) : a(std::move(o.a)), b(std::move(o.b)) {
        std::cout << "Move constructor" << '\n';
        o.a = 0;
        o.b = 0;
    }

    // Move assignment
    X& operator=(X&& o) {
        std::cout << "Move assignment" << '\n';
        a = std::move(o.a);
        b = std::move(o.b);
        o.a = 0;
        o.b = 0;
        return *this;
    }

    void get() { std::cout << a << ' ' << b << '\n'; }

private:
    int a = 0;
    int b = 0;
};

int main() {
    X x1(10, 20);
    X x2(30, 40);
    X x3(50, 60);

    X m1(std::move(x1));    // Move constructor
    X m2 = std::move(x2);   // Move constructor

    X m3;
    m3 = std::move(x3);     // Move assignment

    std::cout << "----------" << '\n';
    std::cout << "m1 : ", m1.get();
    std::cout << "m1 : ", m2.get();
    std::cout << "m1 : ", m3.get();
    std::cout << "----------" << '\n';
    std::cout << "x1 : ", x1.get();
    std::cout << "x2 : ", x2.get();
    std::cout << "x3 : ", x3.get();
}
```
Output
```
Move constructor
Move constructor
Move assignment
----------
m1 : 10 20
m1 : 30 40
m1 : 50 60
----------
x1 : 0 0
x2 : 0 0
x3 : 0 0
```
