```cpp
#include <iostream>

class A {
public:
    int v_public = 1;
protected:
    int v_protected = 2;
private:
    int v_private = 3;
};

class B : public A {
public:
    B() {
        v_public++;     // Yes
        v_protected++;  // Yes
        v_private++;    // No
    }
};

class C : protected A {
    C() {
        v_public++;     // Yes
        v_protected++;  // Yes
        v_private++;    // No
    }
};

class D : private A {
    D() {
        v_public++;     // Yes
        v_protected++;  // Yes
        v_private++;    // No
    }
};

int main() {
    /*B b;
    C c;
    D d;
    std::cout << b.v_public    << '\n';  // ✔ v_public    is public
    std::cout << b.v_protected << '\n';  // ❌ v_protected is protected  
    std::cout << b.v_private   << '\n';  // ❌ v_private   is not inherited
    
    std::cout << c.v_public    << '\n';  // ❌ v_public    is protected
    std::cout << c.v_protected << '\n';  // ❌ v_protected is protected
    std::cout << c.v_private   << '\n';  // ❌ v_private   is not inherited
    
    std::cout << d.v_public    << '\n';  // ❌ v_public    is private
    std::cout << d.v_protected << '\n';  // ❌ v_protected is private
    std::cout << d.v_private   << '\n';  // ❌ v_private   is not inherited
    */
}
```