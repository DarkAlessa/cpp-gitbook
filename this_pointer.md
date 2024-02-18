
type ของ this ในฟังก์ชันสมาชิกของ class X คือ X*
เช่น
```cpp    
    class X {/*..*/};
    X* this;    // this คือชนิด X*
```
ข้อกำหนด
[1] this ใช้ใน body ของ non-static เมมเบอร์ฟังก์ชันรวมถึง member initializer list และ lambda-expression body
[2] this ใช้ภายในการประกาศ non-static member function ที่ใดก็ได้หลังจากลำดับ cv-qualifier
[3] this ใช้ภายใน default member initializer
[4] this ใช้ภายใน lambda-expression capture list

```cpp
class Outer {
    int a[sizeof(*this)];            // error: not inside a member function
    unsigned int sz = sizeof(*this); // OK: in default member initializer
 
    void f(){
        int b[sizeof(*this)];     // OK
 
        struct Inner {
            int c[sizeof(*this)]; // error: not inside a member function of Inner
                                  // 'this' is not associated with Outer
                                  // even if it is inside a member function of Outer
        };
    }
};
```
```cpp
class X {
public:
  X(int a) : a(a) {
    /* a ในวงเล็บเป็น parameter ส่วน a() เท่ากับ this->a */
  }

  X(int b) : b(b), a(this->b) {
    /* ใช้ data member b ใน initialize data member a หรือ a() */
  }

  int A(int a) {
    a = a;        // a เป็นตัวแปร parameter ทั้งคู่
    thia->a = a;  // this->a คือ data member ของ class ส่วน a เป็น parameter
  }

private:
  int a;
  int b;
};
```

EX 1
```cpp
#include <iostream>
using namespace std;
  
class Test {
private:
  int x;
  int y;
public:
    Test(int x) : x(x), y(this->x) {}
    int getX() { return x; }
    int getY() { return y; }
};
  
int main() {
    Test a(10);
    cout << a.getX() << endl;
    cout << a.getY() << endl; 
}
```
EX 2
```cpp
// chain function calls
#include <iostream>
using namespace std;

class X {
public:
    X(int a = 0, int b = 0) : a(a), b(b) {}
    X& setA(int a) {
        this->a = a;
        return *this;
    }
    X& setB(int b) {
        this->b = b;
        return *this;
    }
    int getA() const { return a; }
    int getB() const { return b; }
    
private:
    int a;
    int b;
};

int main() {
    X x(10,10);
    x.setA(5).setB(5);
    cout << x.getA() <<" "<< x.getB() << endl;
}
```
EX 3
```cpp
#include<iostream>
using namespace std;
  
class Test {
private:
  int x;
public:
  Test(int x = 0) { this->x = x; }
  void change(Test *t) { this->x = t->x; }
  void print() { cout << "x = " << x << endl; }
};
  
int main() {
  Test obj(5);
  Test *ptr = new Test (10);
  obj.change(ptr);
  obj.print();
  return 0;
}
```
EX 4
```cpp
#include<iostream>
using namespace std;
  
class Test {
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  static void fun1() { cout << "Inside fun1()"; }
  void fun2() { cout << "Inside fun2()"; this->fun1(); }
};
  
int main() {
  Test obj;
  obj.fun2();
  return 0;
}
```
EX 5
```cpp
#include<iostream>
using namespace std;
  
class Test {
private:
  int x;
  int y;

public:
  Test(int x = 0, int y = 0) { 
    this->x = x;
    this->y = y;
    cout << "Constructor" << endl;
  }

  ~Test() {
    cout << "Destructor" << endl;
  }

  void setX(int a) { x = a; }
  void setY(int b) { y = b; }
  void destroy() { delete this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
  
int main() {
  Test* obj =  new Test(10,20);
  obj->print();
  obj->destroy();
  return 0;
}

/* Output
Constructor
x = 1 y = 3
Destructor
*/
```

EX 6
```cpp
/* ใช้กับ Operator overloading
  x3 = x1 + x2;
  X1 operator+(X2 x) {
    this->x = this->x + x.x; // this เป็นชนิด X1*
    return *this;
  } */
#include <iostream>

class X {
public:
    X(int x) : x(x) {}
    int getX() { return x; };
    X& operator+(const X& x) {
        this->x -= 1;         // ตอนนี้ x1 = 9
        this->x += x.x;
        return *this;
    }

private:
    int x = 0;
};

int main() {
    X x1(10);
    X x2(20);
    X x3 = x1 + x2;
    std::cout << x3.getX() << '\n';
}
/* Output
29
*/
```