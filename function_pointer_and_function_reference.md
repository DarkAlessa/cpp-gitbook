```c++
#include <iostream>

int func1(int x) { return x + 10; }
int func2(int x, int y) { return x + y; }
void func3() { std::std::cout << "func3" << '\n'; }
 
int main()
{
    int (*fptr1)(int) = &func1;
    std::std::cout << (*fptr1)(2) << '\n';
    
    int (*fptr2)(int, int) = &func2;	// int (*fptr2)(int,int) = func2;  ไม่มี & ก็ได้
    std::std::cout << (*fptr2)(10,20) << '\n';
    
    void (*fptr3)() = &func3;
    (*fptr3)();			// หรือ fptr3(); ไม่มี * ก็ได้
        
    void (&fref)() = func3;		// function reference
    fref();
}
```

Output
```
12
30
func3
func3
```

### Funcion pointer to member function
```c++
#include <iostream>

class X {
public:
    void a() { std::cout << "Hello World" << '\n'; }
};

int main() {
    X* ptr = NULL;
    X obj;
    void (X::*foo)() = &X::a;
    (ptr->*foo)();
    (obj.*foo)();
}
```
Output
```
Hello World
Hello World
```
---
```c++
#include <iostream>

class X {
public:
  int a;
  void f(int b) {
    std::cout << "The value of b is "<< b << '\n';
  }
};

int main() {

  // declare pointer to data member
  int X::*ptiptr = &X::a;

  // declare a pointer to member function
  void (X::*ptfptr)(int) = &X::f;

  // create an object of class type X
  X xobject;

  // initialize data member
  xobject.*ptiptr = 10;

  std::cout << "The value of a is " << xobject.*ptiptr << '\n';

  // call member function
  (xobject.*ptfptr) (20);
}
```
Output
```
The value of a is 10
The value of b is 20
```

### const function pointer
```cpp

#include <iostream>

void fx() {
    std::cout << "fx" << "\n";
}

void fg() {
    std::cout << "fg" << '\n';
}

int main() {
    void (*const fp)() = fx;
    fp();
    // fp = fg; // ❌ error: assignment of read-only variable 'fp'

}
```
