```c++
#include <cstdio> 

int main() { 
  printf("Hello World!\n"); 
  return 0; 
} 
```
```
//-------- Linux
# gcc main.c -o main
# ./main.exe
Hello World
# echo $?
0

// ถ้าไม่ใส่ return 0 คอมไพเลอร์จะใส่ให้อัตโนมัติ โดยค่า default คือ return 0
```