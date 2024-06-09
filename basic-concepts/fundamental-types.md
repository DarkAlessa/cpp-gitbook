# 💠 Fundamental types
## 🔶 Types
### 1. Integer
- `int` : ประเภทจำนวนเต็มพื้นฐาน คีย์เวิร์ด `int` อาจถูกละเว้นหากใช้ `modifiers` ใด ๆ ที่แสดงด้านล่าง
#### Modifiers
- Signedness
    - `signed` : ปรับให้ type มี signed-bit (ค่าเริ่มต้น)
    - `unsigned` : ปรับให้ type ไม่มี signed-bit
- Size
    - `short` : ปรับให้ type มีขนาดอย่างน้อย 16 bits
    - `long` : ปรับให้ type มีขนาดอย่างน้อย 32 bits
    - `long long` ปรับให้ type มีขนาดอย่างน้อย 64 bits
```cpp
int a      = 10;
long b     = 20;    // มีค่าเท่ากับ long int b     = 20;
short c    = 30;    // มีค่าเท่ากับ short int c    = 30;
signed d   = 40;    // มีค่าเท่ากับ signed int d   = 40;
unsigned e = 50;    // มีค่าเท่ากับ unsigned int e = 50;
```
---
### 2. Boolean
- `bool` : เป็นชนิด `int` ที่เก็บได้แค่สองค่าคือ `0`, `1` หรือ `true`, `false`
```cpp
bool a = 0;
bool b = 1;
bool c = true;
bool d = false;
```
---
### 3. Character types
- `char` : type สำหรับตัวอักษร
- `signed char` : type สำหรับตัวอักษร (มี signed-bit)
- `unsigned char` : type สำหรับตัวอักษร (ไม่มี signed-bit) 
```cpp
char a = 'A';
char b = 'B';
```
---
### 4. Floating-point
- `float` : ชนิด single precision floating-point (32 bits)
- `double` : ชนิด double precision floating-point (64 bits)
- `long double` : ชนิด quad precision floating-point (128 bits)
```cpp
float a  = 1.0f;
double b = 3.14;
```
