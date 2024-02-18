cmake_minimum_required(VERSION 3.24.0)
project(alice)

#set(my_var "Hello World")
#message("///////////////////////////////////////////")
#message(${my_var})
#message("///////////////////////////////////////////")

message(${CMAKE_CURRENT_BINARY_DIR})
message(${CMAKE_BINARY_DIR})
message(${PROJECT_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})