```cpp
int main(int argc, char *argv[]) {}
int main(int argc, char **argv) {}
```

```cpp
int main() {
    char a[3] = {'A', 'B', 'C'};
    
    char *argv1[] = {&a[0], &a[1], &a[2]};
    
    char **argv2  = &argv1[0];
    
    std::cout << *argv1[0]   << '\n';
    std::cout << *argv1[1]   << '\n';
    std::cout << *argv1[2]   << '\n';    
    std::cout << "=====\n";
    std::cout << **(argv2+0) << '\n';
    std::cout << **(argv2+1) << '\n';
    std::cout << **(argv2+2) << '\n';
}
```