```cpp
#include <iostream>
#include <string>
#include <new>

void* operator new(size_t size) {
	std::cout << "Overloading new operator with size: " << size << '\n';
	return malloc(size);
}

void operator delete(void* p) {
    std::cout << "Overloading delete operator " << '\n';
    free(p);
}

int main() {
    int* x = new int(10);
    std::cout << *x << '\n';
    delete x;
}
```