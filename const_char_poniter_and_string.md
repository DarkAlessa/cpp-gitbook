```cpp
#include <iostream>

int main() {
    // char *a = "Lisa";	warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
    const char *a = "hello";	// OK

    // string *b = "Elsa";	error: cannot convert ‘const char*’ to ‘std::string* {aka std::basic_string*}’ in initialization
    // const string *b = "Elsa";error: cannot convert ‘const char*’ to ‘const string* {aka const std::basic_string*}’ in initialization
    const string &b = "Elsa";	// OK
    
    std::cout << a <<'\n';
    std::cout << b <<'\n';

    return 0;
}
```
output
```console
Lisa
Elsa
```
