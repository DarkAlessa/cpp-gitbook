```c++
int main() {
    std::vector a(2, 1); // 🤔
    for (int i : a)
        std::cout << i << ' ';	// 1 1
}
```

```c++
int main() {
  //std::vector<std::vector<int>> a(2, std::vector<int>(2)); 
    std::vector a(2, std::vector<int>(2));  // 🤔
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 2;
    a[1][1] = 3;
    
    for (auto& x : a) {
        for (int i : x) {
            std::cout << i << ' ';
        }
    }
}
/*
Output
0 1 2 3
*/
```