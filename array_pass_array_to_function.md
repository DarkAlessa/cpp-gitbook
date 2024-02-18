```cpp
#include <iostream>

void arrFunc(int *arr) {
    int a[5] = {*arr, *arr+1, *arr+2, *arr+3, *arr+4};
    for(size_t v : a) {
        std::cout << v << " ";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    arrFunc(arr);
  return 0;
}
//////////////////////////////////////////////////////
/* Output
1 2 3 4 5
*/
```