CMake มีคุณสมบัติการสืบทอด Interitance คล้าย C++ โดยมี `PUBLIC`, `PRIVATE`, และ `INTERFACE`
- `PUBLIC` : จะทำให้ไดเร็กทอรีพร้อมใช้งานในเป้าหมายปัจจุบันและเป้าหมายที่ต้องพึ่งพา
- `PRIVATE` : จะทำให้ไดเร็กทอรีพร้อมใช้งานสำหรับเป้าหมายปัจจุบันเท่านั้น
- `INTERFACE` : ทำให้ไดเร็กทอรีพร้อมใช้งานสำหรับเป้าหมายที่ต้องพึ่งพา แต่ไม่ใช่เป้าหมายที่ประกาศไดเร็กทอรี!

```
📁 demo/
 ├─📄 CMakeLists.txt      ---(1)
 ├─📁 src/
 │  ├─📄 CMakeLists.txt   ---(2)
 │  └─📄 demo.cpp
 ├─📁 lib/
 │  ├─📄 CMakeLists.txt   ---(3)
 │  ├─📁 src/
 │  │  └─📄 math.cpp
 │  └─📁 include/
 │     └─📄 math.h
 ├─📁 bin
 └─📁 build
```
demo/src/demo.cpp
```cpp
#include "math.h"
#include <iostream>
#include <string>

int main() {
    int a = 10;
    int b = 20;
    int x = plus(a, b);

    std::cout << x << '\n';
}
```
demo/lib/src/math.cpp
```cpp
#include "math.h"

int plus(int a, int b){
    return a + b;
}
```
demo/lib/include/math.h
```cpp
#ifndef MATH_H
#define MATH_H

int plus(int a, int b);

#endif // MATH_H
```
---
#### demo/CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.24 FATAL_ERROR)
project(demo C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

add_subdirectory(src)
add_subdirectory(lib)
```
---
### PUBLIC
#### demo/src/CMakeLists.txt ---(2)
```cmake
add_executable(demo demo.cpp)

#target_include_directories(demo PRIVATE ${CMAKE_SOURCE_DIR}/lib/include) ❌

target_link_libraries(demo PRIVATE math)
```
#### demo/lib/CMakeLists.txt ---(3)
```cmake
add_library(math 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp
)

# การกำหนดเป็น PUBLIC แปลว่า dir นี้ใช้ได้กับ target ที่นี้และ target ที่ที่นำไปใช้(consuming targets)
# consuming targets ไม่จำเป็นต้องใช้ target_include_directories() เพราะได้รับการสืบทอดแบบ PUBLIC
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
```
---
### PRIVATE
#### demo/src/CMakeLists.txt ---(2)
```cmake
add_executable(demo demo.cpp)

target_include_directories(demo PRIVATE ${CMAKE_SOURCE_DIR}/lib/include) ✔

target_link_libraries(demo PRIVATE math)
```
#### demo/lib/CMakeLists.txt ---(3)
```cmake
add_library(math 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp
)

# การกำหนดเป็น PRIVATE แปลว่า dir นี้ใช้ได้กับ target ที่นี้เท่านั้น
# consuming targets จำเป็นต้องใช้ target_include_directories() ด้วยตัวเอง
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
```
---
### INTERFACE
ไลบรารี `INTERFACE` เป็น `target` ชนิดพิเศษที่ไม่ได้สร้างโค้ดใดๆ หรือสร้างไฟล์ไลบรารีจริง แต่จะกำหนดชุดของคุณสมบัติที่สามารถใช้โดย `target` อื่นที่ขึ้นอยู่กับมัน
ทำหน้าที่เป็น "ส่วนต่อประสาน" เพื่อให้ข้อมูลเกี่ยวกับตัวเลือกการคอมไพล์ รวมไดเร็กทอรี และคุณสมบัติอื่นๆ ที่ `consuming target` ควรใช้
ไลบรารี `INTERFACE` มักจะใช้เพื่อกำหนดการตั้งค่าทั่วไปหรือข้อกำหนดสำหรับหลายเป้าหมายภายในโครงการ CMake
ตัวอย่างเช่น หากคุณมี target ที่เรียกใช้งานได้หรือไลบรารีหลายรายการที่ต้องใช้แฟล็กคอมไพเลอร์เดียวกัน, include ไดเรกทอรี, หรือการตั้งค่าอื่นๆ คุณสามารถกำหนดการตั้งค่าเหล่านี้ในไลบรารี `INTERFACE` และทำให้เป้าหมายอื่นๆ ขึ้นอยู่กับไลบรารีนั้น ด้วยวิธีนี้ พวกเขาจะสืบทอดคุณสมบัติของไลบรารี `INTERFACE` โดยไม่ทำซ้ำการตั้งค่าในแต่ละเป้าหมายอย่างชัดเจน

#### Ex 1 compile options INTERFACE library
```cmake
add_library(MyInterfaceLibrary INTERFACE)
target_compile_options(MyInterfaceLibrary INTERFACE -Wall -Wextra)
target_include_directories(MyInterfaceLibrary INTERFACE include/)

add_executable(MyExecutable main.cpp)
target_link_libraries(MyExecutable PRIVATE MyInterfaceLibrary)
```
เมื่อทำเช่นนี้ `MyExecutable` จะสืบทอดตัวเลือกการคอมไพล์และรวมไดเร็กทอรีที่ระบุใน `MyInterfaceLibrary`
การใช้ไลบรารี `INTERFACE` สามารถช่วยลดความซับซ้อนของไฟล์ `CMakeLists.txt` ส่งเสริมความสอดคล้องกันระหว่างเป้าหมาย และเปิดใช้งานการแบ่งปันรหัสและโมดูลาร์ที่ดีขึ้นในโครงการ CMake
#### Ex 2 INTERFACE libraries for include directories
```cmake
# Define the INTERFACE library
add_library(MyInterfaceLibrary INTERFACE)

# Set the include directories for the INTERFACE library
target_include_directories(MyInterfaceLibrary INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/other_include)

add_executable(MyExecutable main.cpp)
target_link_libraries(MyExecutable PRIVATE MyInterfaceLibrary)
```
### INTERFACE V.1
#### demo/src/CMakeLists.txt ---(2)
```cmake
add_executable(demo demo.cpp)

target_link_libraries(demo PRIVATE math interface_lib)
```
#### demo/lib/CMakeLists.txt ---(3)
```cmake
add_library(math 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp)

add_library(interface_lib INTERFACE)
target_include_directories(interface_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
```
---
### INTERFACE V.2
#### demo/src/CMakeLists.txt ---(2)
```cmake
add_executable(demo demo.cpp)

target_link_libraries(demo PRIVATE math)
```
#### demo/lib/CMakeLists.txt ---(3)
```cmake
add_library(math 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp
)

add_library(interface_lib INTERFACE)
target_include_directories(interface_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

# ถ้ากำหนดเป็น PRIVATE ทาเก็ทที่ใช้งานไลบรารี่ math นี้ต้อง include directory เอง
target_link_libraries(math PUBLIC interface_lib)
```