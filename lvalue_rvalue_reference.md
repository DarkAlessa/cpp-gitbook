& 	   can bind to non-const lvalues
const &     can bind to rvalues (prvalues and xvalues) and lvalues (const and non-const for each). A.k.a. to anything.
&&	   can bind to non-const rvalues (prvalues and xvalues)
const &&	   can bind to rvalues (const and non-const)
---
### lvalue ref
```cpp
    std::string a = "Hello";
    const std::string b = "World";
    
    std::string& c = a;     	    // OK
    std::string& d = b;     	    // Error: binding reference of type ‘std::string&’ to ‘const string’
    std::string& e = "Hello world"; // Error: cannot bind non-const lvalue reference of type ‘std::string&’ to an rvalue of type ‘std::string’
    std::string& f = a + b; 	    // Error: cannot bind non-const lvalue reference of type ‘std::string&’ to an rvalue
    
    const std::string& g = a; 	// OK
    const std::string& h = b; 	// OK
    const std::string& i = "Hello world"; // OK
    const std::string& j = a + b; // OK
```
---
### rvalue ref
```cpp
    std::string a = "Hello";
    const std::string b = "World";
    
    std::string&& c = a;     // Error: cannot bind rvalue reference of type ‘std::string&&’ to lvalue of type ‘std::string’
    std::string&& d = b;     // Error: cannot bind rvalue reference of type ‘std::string&&’ to lvalue of type ‘const string’
    std::string&& e = "Hello world"; // OK
    std::string&& f = a + b;   // OK
    
    const std::string&& g = a; // Error: cannot bind rvalue reference of type ‘const string&&’ to lvalue of type ‘std::string’
    const std::string&& h = b; // Error: cannot bind rvalue reference of type ‘const string&&’ to lvalue of type ‘const string’
    const std::string&& i = "Hello world"; // OK
    const std::string&& j = a + b;  // OK
```
