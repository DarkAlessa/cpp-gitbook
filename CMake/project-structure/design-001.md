```
📁 Demo
 ├─📄 CMakeLists.txt      ---(1)
 ├─📁 include
 │  ├─📄 source-01.h
 │  └─📄 source-02.h
 ├─📁 src
 │  ├─📄 CMakeLists.txt   ---(2)
 │  ├─📄 main.cpp
 │  ├─📄 source-01.cpp
 │  └─📄 source-02.cpp
 ├─📁 lib
 ├─📁 bin
 └─📁 build
```

### Project/CMakeLists.txt	---(1)
```cmake
cmake_minimum_required(VERSION 3.26 FATAL_ERROR)
project(demo VERSION 1.0.0 LANGUAGES C CXX)

# compiler flags/options INTERFACE
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE $<BUILD_LOCAL_INTERFACE:cxx_std_23>)
target_compile_options(compiler_flags BEFORE INTERFACE
    $<BUILD_LOCAL_INTERFACE:-Wall;-Werror;-Wpedantic>
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")

# include directory INTERFACE
add_library(include_interface INTERFACE)
target_include_directories(include_interface INTERFACE
    $<BUILD_LOCAL_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

add_subdirectory(src)
```

### Project/src/CMakeLists.txt	---(2)
```cmake
add_library(archive)
target_sources(archive PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source-01.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source-02.cpp
)

target_link_libraries(archive PUBLIC include_interface compiler_flags)

add_executable(main WIN32)
target_sources(main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(main PRIVATE archive compiler_flags)
```

### Command
#### Generate a Project Buildsystem
```console

cmake -S . -B ./build -G "MSYS Makefiles"

```
#### Build a Project
```console

cmake --build ./build

```