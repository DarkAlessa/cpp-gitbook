```cpp
#include <iostream>
#include <type_traits>
/*
std::is_lvalue_reference
std::is_rvalue_reference

std::is_reference
std::is_pointer
*/

class A {};

int main() {
	std::cout << std::is_lvalue_reference<A>::value << '\n';
	std::cout << std::is_lvalue_reference<A&>::value << '\n';
	std::cout << std::is_rvalue_reference<A>::value << '\n';
	std::cout << std::is_rvalue_reference<A&>::value << '\n';
	std::cout << std::is_rvalue_reference<A&&>::value << '\n';
}

/* Output
0
1
0
0
1
*/
```