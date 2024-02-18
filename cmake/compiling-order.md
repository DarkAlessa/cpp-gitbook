a.hpp ───── a.cpp	   ───── a.o    ──╮
   ├───────	main.cpp ───── main.o ──┼───── main.exe 
b.hpp ───── b.cpp    ───── b.o    ──╯  ╲
                       ╱                [g++ a.o b.o main.o -o main]
         [g++ *.cpp -c]				    // Linking state (.lib, .a)
         Object file


g++ foo.cpp -c             // จะได้ไฟล์ foo.o โดยดีฟอลต์
g++ foo.cpp -c -o name.o   // -o สร้างไฟล์ output ที่มีชื่อ name.o

-----------------------------------------------------------------------

Archive library (or Static Library) ถูกรวมเข้าไปอยู่ใน executable (.exe) ไฟล์
   .a    // Linux/Unix
   .lib  // Windows

Shared library (or Dynamic Library) เป็นไลบรารีที่สามารถใช้ซ้ำได้ในหลายโปรแกรม
   .so   // Linux/Unix
   .dll  // Windows

--Library --------------------------------------------------------------

// Archive/Static library
   g++ mylib.cpp -c        // mylib.o
   ar rcs mylib.a mylib.o 

// Linking archive/static library
   g++ -std=c++20 -Wall main.cpp mylib.a -o main
or
   g++ -std=c++20 -Wall main.o mylib.a -o main

-----------------------------------------------------------------------
// Shared libray
   g++ mylib.cpp -c        // mylib.o
   g++ -shared mylib.o -o mylib.so 

// Create the executable by linking shared library
   g++ -L<path to .SO file> -Wall main.o -o main -l<library name>

Example
   g++ -L`pwd` -Wall main.o -o main -lmylib

// Make shared library available at runtime
   export LD_LIBRARY_PATH=<path to .SO file>

Example
// /home/Dev/Cpp/mylib.so
   export LD_LIBRARY_PATH=/home/Dev/Cpp

// Run executable
   ./main.exe