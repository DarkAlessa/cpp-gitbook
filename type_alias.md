```cpp
template<template-parameter-list>
using identifier attr(optional) = type-id;
```

```cpp
template<typename T>
using ptr = T*;
  
int main() {
    int i = 10;
    char c = 'A';
    
    ptr<int> iPtr = &i;
    ptr<char> cPtr = &c;
    
    cout << *iPtr << endl;
    cout << *cPtr << endl;
}
```
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

template<class... Args>		// Parameter pack(since C++11)
using tp = std::tuple<Args...>;

int main() {
	tp<std::string, std::string, int> girl = {"Lalisa", "Manoban", 25};
	auto&& [first_name, last_name, age] = girl;   // structure binding
	std::cout << first_name << " " << last_name << ", " << age << '\n';
}
```