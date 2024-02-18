```c++
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::stringstream sst;
    sst << "Answer: " << 1.5 <<  " x " << 3.5 << " = " << 1.5 * 3.5;
    std::string ss = sst.str();
    std::cout << ss;
}
```
