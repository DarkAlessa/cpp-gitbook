```
# แบบทั่วไป
add_executable(demo ${CMAKE_SOURCE_DIR}/src/demo.cpp) 

# ใช้ target_sources()
add_executable(demo)
target_sources(demo PRIVATE ${CMAKE_SOURCE_DIR}/src/demo.cpp)
```