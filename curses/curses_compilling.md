# `NCurses `
os : `POSIX`
ncurses จะไม่มี popup วินโดว์
```bash
	g++ app.cpp -o app -lncurses
# หรือ
	g++ app.cpp -o app -lncursesw
```
# `PDCurses`
os : (`DOS`, `OS/2`, `Win32`, `X11`, `SDL 1/2`)
```bash
	g++ app.cpp -o app -lpdcurses
```

## Example
```cpp
#include <ncurses/ncurses.h>
#include <iostream>
#include <string>

int main() {
    initscr();
    addstr("Hello");
    getch();
    endwin();
}
```
