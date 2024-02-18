```cpp
#include <iostream>

class A {
public:
    A() = default;
    A(int a)    { n = a; }
    A(double b) { m = b; }
    
    // Operator conversion functions
    operator int()    const { return n; }
    operator double() const { return m; }
    
private:
    int n;
    double m;
};

int main() {
    A a_int(10);
    A a_double(1.5);
    int x = a_int;		    // a_int คือ object
    double y = a_double;	// a_double คือ object
    std::cout << x << '\n';
    std::cout << y << '\n';
}
/* Output
10
1.5
*/
```