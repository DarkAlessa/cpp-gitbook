```
📁 Project
 ├─📁 build
 ├─📄 CMakeLists.txt
 └─📁 level_1
    ├─📄 CMakeLists.txt
    └─📁 level_2
       ├─ CMakeLists.txt
       └─📁 level_3
          └─📄 CMakeLists.txt  <--- message() ที่นี่
```
message() จาก CMakeLists.txt ใน level_3
```
PROJECT_SOURCE_DIR       : /Project
CMAKE_SOURCE_DIR         : /Project
PROJECT_BINARY_DIR       : /Project/build
CMAKE_BINARY_DIR         : /Project/build
CMAKE_CURRENT_SOURCE_DIR : /Project/level_1/level_2/level_3
CMAKE_CURRENT_BINARY_DIR : /Project/build/level_1/level_2/level_3
```

PROJECT_SOURCE_DIR และ PROJECT_BINARY_DIR จะอ้างอิงจาก CMakeLists.txt มี่มี project() 
	ถ้า subdirectory มี CMakeLists.txt มี่มี project(), PROJECT_SOURCE_DIR จะอยู่ที่ตำแหน่งนั้น
```
📁 Project
 ├─📁 build
 ├─📄 CMakeLists.txt  <----------- project(level_1)           
 └─📁 level_1
    ├─📄 CMakeLists.txt
    └─📁 level_2
       ├─ CMakeLists.txt <------ project(level_2)
       └─📁 level_3
          └─📄 CMakeLists.txt  <--- message() ที่นี่
```
message() จาก CMakeLists.txt ใน level_3
```
PROJECT_SOURCE_DIR       : /Project/level_1
CMAKE_SOURCE_DIR         : /Project
PROJECT_BINARY_DIR       : /Project/build/level_1
CMAKE_BINARY_DIR         : /Project/build
CMAKE_CURRENT_SOURCE_DIR : /Project/level_1/level_2/level_3
CMAKE_CURRENT_BINARY_DIR : /Project/build/level_1/level_2/level_3
```

CMAKE_SOURCE_DIR จะอ้างอิงจาก CMakeLists.txt ที่อยู่บนสุด
