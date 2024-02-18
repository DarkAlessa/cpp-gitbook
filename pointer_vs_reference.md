### Pointer
```cpp                                                           
int x = 10;
int *xPtr = &x;
	// -Assigns the address of x to the variable xPtr
	// -xPtr is said to "point to" x.
	// * is the indirection or dereferencing operator.
```
```cpp
#include <iostream>

void swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << "a = " << a << " " << "b = " << b << '\n';
    swap(&a, &b);
    std::cout << "a = " << a << " " << "b = " << b <<'\n';
}

/* Output
a = 10 b = 20
a = 20 b = 10
*/
```
----------------------------------------------------------------------------
### Reference
```cpp                                                                
int x = 10;
int &xRef = x;

int &xRef; // ✘ Error: 'iRef' declared as reference but not initialized
xRef = x;               
```
```cpp
#include <iostream>

void swap(int &px, int &py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << "a = " << a << " " << "b = " << b << '\n';
    swap(a, b);
    std::cout << "a = " << a << " " << "b = " << b << '\n';
    
    return 0;   
}
/* Ouput:
a = 10 b = 20
a = 20 b = 10
*/
```
----------------------------------------------------------------------------
### Const Referent
```cpp
#include <iostream>

int main() {
	int x = 10;
	const int &xRef = x;

	/* xRef = 20;
	 * error: assignment of read-only reference ‘xRef’
	 */
	const_cast<int&>(xRef) = 20;
	std::cout << x <<'\n';   // 20

	/* int &yRef{xRef}; 
	 * error: binding reference of type ‘int&’ to ‘const int’ discards
 	 * qualifiers
	 */
	int &yRef = const_cast<int&>(xRef);
	yRef = 20;
	std::cout << x; // 20
}
```
