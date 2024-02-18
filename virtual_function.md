`virtual function` คือฟังก์ชั่นสมาชิกที่สามารถ `override` ในคลาสลูก (`derived class`) ได้ ฟังก์ชั่นที่ override ในคลาสลูกจะเป็น virtual function (ไม่ว่าจะใช้ keyword `virtual` ในการประกาศหรือไม่ก็ตาม)

```cpp
#include <iostream>

class A {
public:
    virtual void fn() = 0;
};

class B : public A {
public:
    // B::fn เป็น virtual function
    void fn() override {
        std::cout << "Class B" << '\n';
    } 
};

class C : public B {

};

int main() {
    B b;
    b.fn();

    C c;
    c.fn();
}
/* Output
 Class B
 Class B
*/
```