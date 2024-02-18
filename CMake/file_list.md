
📁 Demo
 ├──📄 CMakeLists.txt
 ├──📄 a.cpp
 ├──📁 dir1
 │   └──📄 b.cpp
 └──📁 dir2
  	  ├──📄 c.cpp
  	  └──📁 dir3
  	      └──📄 d.cpp


------- CMakeLists.txt ------------------------------------
cmake_minimum_required(VERSION 3.20)
project(dirtest)

# Generate a list of files : file()
# โหมด GLOB_RECURSE จะสำรวจไดเร็กทอรีย่อยทั้งหมด
file(GLOB         all_file_1 "${PROJECT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE all_file_2 "${PROJECT_SOURCE_DIR}/*.cpp")

message(${all_file_1})
# all_file_1 = a.cpp 

message(${all_file_2})
# all_file_2 = a.cpp, b.cpp, c.cpp, d.cpp
