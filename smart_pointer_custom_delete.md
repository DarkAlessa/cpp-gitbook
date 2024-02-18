```cpp
#include <iostream>
#include <string>
#include <functional> // std::function
#include <memory>     // smart pointer

int main() {
        auto fn = [](int* ptr) {
                std::cout << "Custom Deleter" << '\n';
                delete ptr;
        };

        std::unique_ptr<int, decltype(fn)> up1(new int(10), fn);

        /*
        custom delete ใช้ make_* ไม่ได้ หากต้องการใช้ตัวลบแบบกำหนดเอง คุณต้องสร้างตัวชี้อัจฉริยะโดยตรง
        ฟังก์ชั่น make_* ได้รับการออกแบบให้ทำงานกับตัวลบเริ่มต้นที่มาจากตัวชี้อัจฉริยะ (เช่น delete สำหรับ std::unique_ptr และ std::default_delete สำหรับ std::shared_ptr)
        */
        //auto up1 = std::make_unique<int, decltype(fn)>(new int(10), fn);     // ❌
        auto up2 = std::unique_ptr<int, decltype(fn)>(new int(10), fn);
}

/*
Custom Deleter
Custom Deleter
*/
```
---
```cpp
#include <iostream>
#include <string>
#include <functional> // std::function
#include <memory>     // smart pointer

class Deleter {
public:
    Deleter(int x) : x(x) {}
    ~Deleter() {
        std::cout << "Deleter Class";
    }
private:
    int x;
};

int main() {
        auto fn = [](Deleter* ptr) {
                std::cout << "Custom Deleter" << '\n';
                delete ptr;
        };

        auto up2 = std::unique_ptr<Deleter, decltype(fn)>{new Deleter(10), fn};
}

/* Output
Custom Deleter
Deleter Class
*/
```