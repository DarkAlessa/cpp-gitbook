### main.cpp
```cpp
#include <iostream>
#include <typeinfo>

int main() {
  std::cout << typeid(std::size_t).name() << '\n';
  std::cout << typeid(int).name() << '\n';
  return 0;
}
```
### compile
```console
$ g++ -Wall -std=c++20 main.cpp -o main
$ ./main.exe | g++filt -t
```

### Output
```console
unsigned long long
int
```
