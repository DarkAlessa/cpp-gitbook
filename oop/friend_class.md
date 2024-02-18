
`friend class` ใน C++ สามารถเข้าถึงสมาชิก `private` และ `protected` ของคลาสซึ่งประกาศเป็น friend
```c++
#include <iostream>
#include <string>

class A {
protected:
    std::string protected_a = "protected variable";
private:
    std::string private_a = "private variable";
    friend class B;
};

class B {
public:
    void getString(A& a) { 
        std::cout << a.protected_a << "\n";
        std::cout << a.private_a << "\n";    
    }
};

int main() {
    A a;
    B b;
    b.getString(a);
}
```
