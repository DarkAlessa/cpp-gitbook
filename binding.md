## Binding
- Static binding (Early binding or Compile-time Binding )
   - Function overloading
   - Operator overloading

 Dynamic binding (Late binding or Runtime binding )
   - Virtual function (Function overriding)

---

### Dynamic binding (or Late binding)

```c++
#include <iostream>
#include <string>

class A {
public:
    virtual void show() { std::cout << "Class A" << '\n'; }
};

class B : public A {
public:
    void show() { std::cout << "Class B" << '\n'; }
};

class C : public A {
public:
    void show() { std::cout << "Class C" << '\n'; }   
};

int main() {
    B b;
    C c;
    A* a;
    a = &b;
    a->show(); // "Class B"
    a = &c;
    a->show(); // "Class A"
}
```