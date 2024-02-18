`static` กับ `anonymous namespace` จะทำให้ function, variable, class, struct ใช้ได้ในเฉพาะ translation unit นั้น ๆ เท่านั้น ในตัวอย่างมีฟังก์ชั่นชื่อเดียวกันคือ fun() ซึ่งเมื่อ compile และ link จะทำให้เกิด error ขึ้นเพราะชื่อซ้ำกัน ในไฟล์ b.cpp ประกาศ anonymous namespace ให้กับฟังก์ชั่น fun() เพื่อให้ใช้ได้เฉพาะใน b.cpp \
ข้อแตกต่างระหว่าง `static` กับ `anonymous namespace` คือ static ใหช้ได้เฉพาะกับ variable และ function ไม่สามารถใช้กับ user-defined types แต่ anonymous namespace ทำได้ \
`translation unit` : คือ `source file` (.cpp, .cc, cxx, ...) ที่รวม .h ไฟล์ 1 sorce file คือ 1 translation unit

a.cpp
```cpp
#include "b.h"
#include <iostream>

void fun() {
    std::cout << "fun() from a.cpp" << '\n';
}

int main() {
    fun();

}
```

b.h
```cpp
#ifndef B_H
#define B_H

void fun();

#endif
```

b.cpp
```cpp
#include "b.h"
#include <iostream>

namespace {
   void fun() { 
        std::cout << "fun() from b.cpp" << '\n';
    }
}
```

output
```
fun() from a.cpp
```