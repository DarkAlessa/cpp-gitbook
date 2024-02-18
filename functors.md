```
functors หรือ function object คือ object ของ class ที่ทำหน้าที่เหมือน function
โดยการ overload operator() ใน class
```
```cpp
class Greet {
public:
  void operator()() {
    // function body
  }
};
```
```cpp
#include <iostream>

class Greet {
public:    
  // overload function call/parentheses operator
  void operator()() {
    std::cout << "Hello World!" << '\n';;
  }
};

int main() {
	// create an object of Greet class
  Greet greet;

  // call the object as a function
  greet();
  greet.operator()(); // same greet();

  return 0;
}

/* Output
Hello World!
Hello World!
*/
```
```cpp
#include <iostream>

class X {
public:
  int operator()(int a, int b) {
   	return a * b;
  }
};

int main() {
	X x;
	int a = x(2,4);		// call functors
	int a = x.operator()(2, 4); // same x(2,4); 
	std::cout << a << '\n';
}

/* Output
8
8
*/
```
```cpp
#include <functional>
#include <iostream>

template<class T>
class Fn {
public:
    Fn() = default;
    Fn(auto&& a) : x(a) {}

    template<typename... U>
    int operator()(const U&... args) {
        return x(args...);
    }

private:
    std::function<T> x = nullptr;
};

int main() {
    Fn<int(int,int)> fn = [](int a, int b) { return a + b; };
    std::cout << fn(1, 2) << '\n';
    
    Fn<int(int,int,int)> fx = [](int a, int b, int c) { return a + b + c; };
    std::cout << fx(1, 2, 3) << '\n';
}

/* Output
3
6
*/
```