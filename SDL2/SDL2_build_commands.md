// Check linker pkg-config
$ pkg-config --cflags --libs sdl2
-IC:/msys64/ucrt64/include/SDL2 -Dmain=SDL_main -lmingw32 -mwindows -lSDL2main -lSDL2

$ pkg-config --cflags --libs sdl2 sdl2_image
-IC:/msys64/ucrt64/include/SDL2 -Dmain=SDL_main -IC:/msys64/ucrt64/include/libpng16 -DHWY_SHARED_DEFINE -DLIBDEFLATE_DLL -lSDL2_image -lmingw32 -mwindows -lSDL2main -lSDL2


// Check linker sdl2-config
$ sdl2-config --cflags --libs
-IC:/msys64/ucrt64/include/SDL2 -Dmain=SDL_main
-LC:/msys64/ucrt64/lib -lmingw32 -mwindows -lSDL2main -lSDL2



// Build command
// Version 01
$ g++ -std=c++17 mycode.cpp -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o mycode

// ถ้ามีโฟลเดอร์ include กับ lib ใน project
$ g++ -std=c++17 mycode.cpp -I"include" -L"lib" -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o mycode

---------------------------------------------------------------------------------------------------------

// Version 02 Command Substitution `...` or $(...)
// `sdl2-config --cflags --libs` ต้องอยู่หลัง *.c, *.cpp ไฟล์
// `sdl2-config --cflags --libs` หรือ $(sdl2-config --cflags --libs)

$ g++ -std=c++17 mycode.cpp -Wall `sdl2-config --cflags --libs` -o mycode

// ใช้ SDL2_image ในโปรเจค
$ g++ -std=c++17 mycode.cpp -Wall `sdl2-config --cflags --libs` -lSDL2_image -o mycode

// ถ้ามีโฟลเดอร์ include กับ lib ใน project
$ g++ -std=c++17 mycode.cpp -I"include" -L"lib" -Wall `sdl2-config --cflags --libs` -o mycode

---------------------------------------------------------------------------------------------------------

// Version 03 pkg-config
$ g++ -std=c++17 mycode.cpp -Wall `pkg-config --cflags --libs sdl2` -o mycode

// // ใช้ SDL2_image ในโปรเจค
$ g++ -std=c++17 mycode.cpp -Wall `pkg-config --cflags --libs sdl2 sdl2_image` -o mycode

// ถ้ามีโฟลเดอร์ include กับ lib ใน project
$ g++ -std=c++17 mycode.cpp -I"include" -L"lib" -Wall `pkg-config --cflags --libs sdl2` -o mycode
