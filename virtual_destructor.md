```cpp
#include <iostream>

class A {
public:
    A(){ std::cout << "A Constructor" << '\n'; }
    virtual ~A(){ std::cout << "A Destructor" << '\n'; }
};

class B : public A {
public:
    B(){ std::cout << "B Constructor" << '\n'; }
    ~B(){ std::cout << "B Destructor" << '\n'; }
};

class C : public B {
public:
    C(){ std::cout << "C Constructor" << '\n'; }
    ~C(){ std::cout << "C Destructor" << '\n'; }
};

int main() {
    A* a = new C;
    std::cout << "-------------" << '\n';
    delete a;
}

/* Output 
A Constructor
B Constructor
C Constructor
-------------
C Destructor
B Destructor
A Destructor
*/

/*
Constructor : A -> B -> C
Destructor  : C -> B -> A
*/
```
```cpp
int main() {
    A* a = new B;
    std::cout << "-------------" << '\n';
    delete a;
}

/* Output
A Constructor
B Constructor
-------------
B Destructor
A Destructor
*/
/*
Constructor : A -> B
Destructor  : B -> A
*/
```