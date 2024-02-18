### main.cpp
```cpp
#include "x.h"
#include <iostream>

int main() {
    fx();
    x = 200;	// ถ้าไม่มี extern (ใน x.h) จะ error
    fx();
    x = 300;
    fx();
}
```

### x.h
```cpp
#ifndef X_H
#define X_H

extern int x;   // extern
void fx();

#endif
```

### x.cpp
```cpp
#include "x.h"
#include <iostream>

int x = 10;

void fx() {
    std::cout << x << '\n';
}
```