```cpp
#include <iostream>
#define EQ  " = "
#define NEQ " ≠ "

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int (*xP)[5] = &arr;
    int* xPP = arr;

    std::cout << "arr[5] size " << sizeof(arr) << " bytes" << '\n';
    std::cout << xPP     << EQ << xP[0]     << EQ  << xP[0] << EQ << xP     << '\n';
    std::cout << xPP + 1 << EQ << xP[0] + 1 << NEQ << xP[1] << EQ << xP + 1 << '\n';
    std::cout << xPP + 2 << EQ << xP[0] + 2 << NEQ << xP[2] << EQ << xP + 2 << '\n';

    /*
        xP[0] = xP
        xP[1] = xP + 1
        xP[2] = xP + 2

        xP[1] ≠ xP[0] + 1
        xP[2] ≠ xP[0] + 2
	
        xP[1] คือ block ถัดไปของ xP[0] ขนาด 20 bytes
    */
}

/* Output
arr[5] size 20 bytes
0x7fff7e170640 = 0x7fff7e170640 = 0x7fff7e170640 = 0x7fff7e170640
0x7fff7e170644 = 0x7fff7e170644 ≠ 0x7fff7e170654 = 0x7fff7e170654
0x7fff7e170648 = 0x7fff7e170648 ≠ 0x7fff7e170668 = 0x7fff7e170668
*/
```

```cpp
#include <iostream>
#define O  " | "
#define N  '\n'

int main() {
    int arr[4] = {1, 2, 3, 4};
    int (*arrP)[4] = &arr;

    std::cout << "arr[4] size " << sizeof(arr) << " bytes" << N;
    std::cout << arr     << O << (&arr)[0]     << O << &arr     << O << (&arr)[0] << O << arrP     << N;
    std::cout << arr + 1 << O << (&arr)[0] + 1 << O << &arr + 1 << O << (&arr)[1] << O << arrP + 1 << N;
    std::cout << arr + 2 << O << (&arr)[0] + 2 << O << &arr + 2 << O << (&arr)[2] << O << arrP + 2 << N;
    std::cout << arr + 3 << O << (&arr)[0] + 3 << O << &arr + 3 << O << (&arr)[3] << O << arrP + 3 << N;
}

/* Output
arr[4] size 16 bytes
0x7ffdb0567580 | 0x7ffdb0567580 | 0x7ffdb0567580 | 0x7ffdb0567580 | 0x7ffdb0567580
0x7ffdb0567584 | 0x7ffdb0567584 | 0x7ffdb0567590 | 0x7ffdb0567590 | 0x7ffdb0567590
0x7ffdb0567588 | 0x7ffdb0567588 | 0x7ffdb05675a0 | 0x7ffdb05675a0 | 0x7ffdb05675a0
0x7ffdb056758c | 0x7ffdb056758c | 0x7ffdb05675b0 | 0x7ffdb05675b0 | 0x7ffdb05675b0
*/
```
