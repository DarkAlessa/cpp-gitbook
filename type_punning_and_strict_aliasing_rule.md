```
pointer หรือ alias ต่างชนิดกันแต่ชี้ไปที่หน่วยความจำตำแหน่งเดียวกัน
  int* i ----> int x <------- float* j
```

```cpp
int foo(int* i, float* j) {
    *i = 1;
    *j = 0.f;
    return *i;
}

int main() {
    int x = 0;
    std::cout << "x = " << x << '\n';
    x = foo(&x, reinterpret_cast<float*>(&x));
    std::cout << "x = " << x << '\n';
}

/* output
x = 0
x = 1

แม้ว่า *j ถูกเปลี่ยนหลังจาก *i แต่ *i ยังคงเป็น 1 🤔
*/
```

```cpp
int main() {
    int x = 0;
    std::cout << "x = " << x << '\n';
    std::cout << "-------------------" << '\n';
    
    int* a = &x;
    float* b = reinterpret_cast<float*>(&x);
    
    *a = 1;
    *b = 0.5f;
    
    std::cout << "*a = " << *a << '\n';
    std::cout << "*b = " << *b << '\n';
    std::cout << "x = " << x << '\n';
    
    std::cout << "-------------------" << '\n';
    
    *b = 0.5f;
    *a = 1;
    
    std::cout << "*a = " << *a << '\n';
    std::cout << "*b = " << *b << '\n';
    std::cout << "x = " << x << '\n';
}

/* output
x = 0
-------------------
*a = 1056964608
*b = 0.5
x = 1056964608
-------------------
*a = 1
*b = 1.4013e-45
x = 1

x ไม่สามารถเก็บค่าจาก *b ที่เป็น float* ได้ ? 🤔
*/
```