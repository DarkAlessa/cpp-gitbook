เมื่อเรียกใช้โอเปอเรเตอร์ new จำเป็นจะต้องทำการ delete ทุกครั้งไม่เช่นนั้นจะทำให้เกิด memory leak \
เรารู้ว่า object ของ class จะถูกทำลาย(เรียกใช้ destructor)เมื่ออยู่นอกสโคป smart pointer เลยใช้คุณสมบัตินี้มาทำเป็น wraper class เพื่อใช้ destructor ลบ(delete)พอยเตอร์ที่ชี้ไปยัง new 

```c++
#include <iostream>

template <class T>
class SmartPtr {
public:
    SmartPtr() : ptr(new T) {}
    ~SmartPtr() { delete ptr; }
    T& operator*() { return *ptr; } // Overloading dereferencing operator
    T* operator->() { return ptr; } // Overloading arrow operator

private:
    T* ptr;
};

class A {
public:
    A() { std::cout << "Constructor" << '\n'; }
    ~A(){ std::cout << "Destructor"  << '\n'; }
    void a_print() {
        std::cout << "From A function" << '\n';
    }
};

int main() {
    SmartPtr<A> sptr;
    sptr->a_print();
}
/////////////////////////////////////////////////////////

// Note บันทัดที่ 9, 10 เรียกว่า "Overloading class member access"

struct Y {
    void f() {};
};

struct X {
    Y* ptr;
    Y* operator->() { return ptr; }
};

int main() {
  X x;
  x->f(); // ถูกตีความเป็น (x.operator->())->f(), x คือ ptr
}
```

---

### std::unique_ptr

```c++
#include <iostream>
#include <memory>

class A {
public:
    A() : x(0), y(0) { std::cout << "Constructor A" << '\n'; }
    A(int x, int y) : x(x), y(y) { std::cout << "Constructor A" << '\n'; }
    virtual ~A() { std::cout << "Destructor A" << '\n'; }
    virtual void print() const { std::cout << "Class A : " << x << ", " << y << '\n'; }

protected:
    int x;
    int y;
};

class B : public A {
public:
    B() : A(0, 0) { std::cout << "Constructor B" << '\n'; }
    B(int x, int y) : A(x, y) { std::cout << "Constructor B" << '\n'; }
    ~B() { std::cout << "Desstructor B" << '\n'; }
    void print() const override { std::cout << "Class B : " << x << ", " << y << '\n'; }
};

int main() {
    {
        std::unique_ptr<A> x = std::make_unique<B>(10, 20);
        // auto x = std::make_unique<B>(10, 20); // x is class B
        x->print();
    }
    std::cout << "--------------\n";
    {
        A* y = new B(30, 40);
        y->print();
        delete y;
    }
}
```
output
```
Constructor A
Constructor B
Class B : 10, 20
Desstructor B
Destructor A
--------------
Constructor A
Constructor B
Class B : 30, 40
Desstructor B
Destructor A
```
---

### std::shared_ptr
std::shared_ptr เป็นตัวชี้อัจฉริยะที่รักษาความเป็นเจ้าของร่วมกันของวัตถุผ่าน pointer \
อ็อบเจกต์ถูกทำลายและหน่วยความจำถูกจัดสรรเมื่อเกิดกรณีต่อไปนี้:
- shared_ptr สุดท้ายที่เหลืออยู่ซึ่งเป็นเจ้าของวัตถุถูกทำลาย
- shared_ptr สุดท้ายที่เหลืออยู่ซึ่งเป็นเจ้าของออบเจกต์ถูกกำหนดให้ตัวชี้อื่นผ่าน operator= หรือ reset()

std::shared_ptr ประกอบไปด้วย 2 ส่วน \
1) pointer ที่เก็บตำแหน่งของ object ที่ชี้
2) pointer ที่ชี้ไปยัง Coltro Block
```
std::shared_ptr ptr(new int(10));

    /---------> managed object (new int)
ptr
    \---------> coltrol block
                        \---pointer to the managed object 
                        |   or the managed object itself
                        \---reference count
                        \---weak count
                        \---deleter
                        \---allocator

```

#### two memory allocations (bad⚠) \
ข้อเสีย \
- managed object และ control block จะสร้างแยกกัน (สร้าง 2 ครั้ง)
- control block จะเก็บตัวชี้ไปยัง managed object 
- ข้อมูลของตัวชี้ที่ใช้ร่วมกันจะอยู่ในส่วนต่างๆ ของฮีปซึ่งอาจนำไปสู่อัตราการพลาดแคชที่สูงขึ้น
```cpp
auto p1 = std::shared_ptr(new int(10));
std::shared_ptr p2(new int(20));
```
```
std::shared_ptr ptr(new int(10));

    /---------> managed object (new int) 🟢 <--------------\
ptr                                                         |
    \---------> coltrol block                               |
                        \---pointer to the managed object --/
                        |   or the managed object itself
                        \---reference count
                        \---weak count
                        \---deleter
                        \---allocator

```

#### one allocation 👍 \
- managed object และ control block จะอยู่ติดกันและถุกสร้างครั้งเดียว
- managed object จะถูกสร้างขึ้นในพื้นที่ data member ของ control block
```cpp
auto p1 = std::make_shared<int>(10);
std::shared_ptr p2 = std::make_shared<int>(20);
```
```
auto ptr = std::make_shared<int>(10);

ptr ---------> coltrol block                               
   \------------------> \---managed object (new int) 🟢
                        \---reference count
                        \---weak count
                        \---deleter
                        \---allocator
```
example: 1
```cpp
#include <iostream>
#include <string>
#include <memory>

class A {
public:
    A()  { std::cout << "Constructor" << '\n'; }
    ~A() { std::cout << "Destructor"  << '\n'; }
};

int main() {
    auto ptr = std::make_shared<A>();   // count = 1
    {
    auto x(ptr);          // count = 2
        {
            auto y(ptr);  // count = 3
            std::cout << ptr.use_count() << '\n';
        }   // delete y here
        std::cout << ptr.use_count() << '\n';
    } // delete x here

    std::cout << ptr.use_count() << '\n';
} // object delete here
```
output
```
Constructor
3
2
1
Destructor
```

### std::weak_ptr
```
lock()      // ถ้า std::weak_ptr::expired รีเทิร์น false จะรีเทิร์น std::shared_ptr managed object
            // ถ้า std::weak_ptr::expired รีเทิร์น true  จะรีเทิร์น default-constructed std::shared_ptr of type T

expired()   // มีค่าเท่ากับ use_count() == 0
```

Ex 1
```cpp
#include <iostream>
#include <memory>

int main() {
    std::weak_ptr<int> w;
    {
        auto sh = std::make_shared<int>(10);
        w = sh;
        std::cout << "weak_ptr count : " << w.use_count() << '\n';
        std::cout << std::boolalpha << "shared pointer expired? : " << w.expired() << '\n';
    }   // sh has been deleted here.

    std::cout << "------ out of scope -----------\n";
    std::cout << "weak_ptr count : " << w.use_count() << '\n';    
    std::cout << std::boolalpha << "shared pointer expired? : " << w.expired() << '\n';
}
```
output
```
weak_ptr count : 1
shared pointer expired? : false
------ out of scope -----------
weak_ptr count : 0
shared pointer expired? : true
```

Ex 2
```cpp
#include <iostream>
#include <memory>

int main() {
    std::weak_ptr<int> w;
    {
        auto sh = std::make_shared<int>(10);
        w = sh;
    }   // sh has been deleted here.
    
    if (w.lock()) {
        std::cout << "Yes, " << *w.lock() << '\n';
    }
    else {
        std::cout << "No" << '\n';
    }

    // if (auto s = w.lock()) {
    //     std::cout << "Yes, " << *s << '\n';
    // }
    // else {
    //     std::cout << "No" << '\n';
    // }
}
```
output
```
No
```
