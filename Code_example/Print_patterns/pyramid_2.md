```cpp
#include <iostream>

int main() {
    int row = 4;
    int col = row;

    for (int i = (row - 1); i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            std::cout << (j >= i ? "* " : "  ");
        }
        col += 1;
        std::cout << '\n';
    }
}

/* output

      * 
    * * * 
  * * * * * 
* * * * * * *

*/
```