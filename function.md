# 📄 function

#### Function Pointer

```cpp
int fn(int a, int b) { return a + b; }
int (*fp)(int,int) = fn;
	
// typedef
typedef int (*FP)(int,int);
FP fp = fn;

// using
using FP = int(*)(int,int);
FP fp = fn;
```

***

#### std::function (function wrapper)

```cpp
#include <functional>
	
int fn(int a, int b) { return a + b; }

struct F {
    int operator()(int a, int b) { return a + b; }
};

int main() {
    std::function<int(int,int)> fx = fn;
    std::function<int(int,int)> ft = F();	// functor or function object
    std::function<int(int,int)> fg = std::bind(fn, std::placeholders::_1, std::placeholders::_2);
    std::function<int(int,int)> fh = [](int x,int y) { return fn(x, y); };
}

```

***

#### Functor/Function Object

```cpp
#include <iostream>

class Functor {
public:
    int operator()(int a, int b) {
        return a * b;
    }
};

int main() {
    Functor ft;
    int a = ft(2, 4);              // call functors
    int b = ft.operator()(2, 4);   // same ft(2,4); 
    std::cout << a << ' ' << b << '\n';
}
```

***

#### Variadic arguments

```cpp
#include <cstdarg>
```

***

#### Function pointer vs std::function

```cpp
#include <iostream>
#include <functional>

int fn(int a, int b) { 
    return a + b; 
}

int main() {    
    std::function<int(int,int)> fx = std::bind(fn, 10, 20);
    int (*fp)(int,int) = [](int,int) { return fn(10, 20); };

    std::cout << fx(0, 0) << '\n';  // 30
    std::cout << fp(0, 0) << '\n';  // 30
}
```

***

#### Lambda expression

```cpp
int fn(int a, int b) { return a + b; }

std::function<int(int,int)> fx = [](int a, int b) { return fn(a, b); };
std::cout << fx(10, 20) << '\n';	// 30

auto fg = [](int a, int b){ return fn(a, b); };
std::cout << fg(10, 20) << '\n';	// 30

/*
Immediately invoked function expressions (IIFE)
    1)	[](){...}();
    2)	std::invoke([](){...}, a, b); // a, b is argument
*/
int a = 10;
int b = 20;
int x = [&a, &b](){ return fn(a, b); }();               // x = 30

int x = [](int a, int b){ return fn(a, b); }(10, 20);   // x = 30

int x = std::invoke([](int a, int b){ return fn(a, b); }, 10, 20);	// x = 30
```

***

#### Callback Function

```cpp
int fn(int a, int b) { return a + b; }
int callback(int a, int b, int(*fp)(int, int)) { return fp(a, b); }
int x = callback(10, 20, fn);
```

#### Using functors for callback

```cpp
#include <iostream>

class Square {
public:
    int operator()(int x) { 
        return x*x; 
    } 
};

class Neg { 
public:
    int operator()(int x) { 
        return -x; 
    } 
};

int timestwo(int x) {
    return 2*x;
}

template<typename T> 
int do_some_process(T process, int x) {
    return process(x);
}

int main() {
    Square a;
    Neg b;
    int x = 9;

    std::cout << do_some_process<Square>(a, 2) << '\n';
    std::cout << do_some_process<Neg>(b, 2)    << '\n';
    std::cout << do_some_process(timestwo, x)  << '\n';
}
```
