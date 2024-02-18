
-------------------------------
### Pointer to Data
```cpp
int a = 10;
int* pt = &a;
```
-------------------------------
### Pointers to Pointers
```cpp
int a = 10;
int* p1 = &a;
int** p2 = &p1;
```
-------------------------------
### Constant Pointers
```cpp
int a = 10;
int* const x = &a;
```
-------------------------------
### Pointer to Constant
```cpp
int a = 10;
const int* x = &a;
```
-------------------------------
### Constant Pointer to a Constant
```cpp
int a = 10;
const int* const x = &a;
```
-------------------------------
### Pointer to an Array
```cpp
int arr[2] = {0, 1};
int* pt1 = arr;
int (*pt2)[2] = &arr;
```
-------------------------------
### Array of Pointers
```cpp
int a[4] = {1,2,3,4};
int *arr[4] = {};
arr[0] = &a[0];
arr[1] = &a[1];
arr[2] = &a[2];
arr[3] = &a[3];
```
-------------------------------
### Pointer Arithmetic
```cpp
int arr[2] = {0, 1};
int* pt = arr;
std::cout << *pt << '\n';
std::cout << *(pt + 1) << '\n';
```
-------------------------------
### Dynamic Memory Allocation
```cpp
class MyClass {...};
int main() {
	MyClass* object = new MyClass();
	delete object;
}
```
-------------------------------
### Pointer to Structures
```cpp
struct Str {...};
int main() {
	Str s;
	Str* ps = &s;
}
```
-------------------------------
### Function Pointer
```cpp
void fn() { std::cout << "hello" << '\n'; }
void (*fp)() = fn;
```
-------------------------------
### Function pointer as argument
```cpp
void fn(int a, int b) { std::cout << a + b << '\n'; }
void callback(int x, int y, void (*fn)(int a, int b)) {
	fn(x, y);
}
int main() {
	callback(10, 20, fn);
}
```
-------------------------------
### Smart Pointers
```cpp
std::unique_ptr
std::shared_ptr
std::weak_ptr
```