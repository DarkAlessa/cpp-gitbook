```cpp
#include <iostream>
#include <string>

int main() {
    int x;
    do {
        std::cout << "Number : ", std::cin >> x;
        try {
            if (x == 5) throw x;
        }
        catch (int e) {
            std::cout << "Error : " << e << '\n';
            break;
        }
    } while (true);
}

/*
Number : 1
Number : 2
Number : 3
Number : 4
Number : 5
Error : 5
*/
```

```cpp
#include <iostream>
#include <string>

template<typename T>
T fn(T v) {
    return v;
}

int main() {
    try {
        auto error = fn(10000);     // "int error"
    //  auto error = fn(20.0f);     // "float error"
    //  auto error = fn(true);      // "default exception"
        throw error;
    }
    catch (int error) {
        std::cout << "int error : "     << error << '\n';
    }
    catch (float error) {
        std::cout << "float error : "   << error << '\n';
    }
    catch (...) {
        std::cout << "default exception" << '\n';
    }
}
```