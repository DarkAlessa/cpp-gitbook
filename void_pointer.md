```c++
int main() {
    int a = 10;
    void* x = &a;
    int* y = (int*)x;
    int z = *(int*)x;

    std::cout << *x << '\n'; // error: 'void*' is not a pointer-to-object type
    std::cout << *y << '\n';
    std::cout << z  << '\n';
}
```
