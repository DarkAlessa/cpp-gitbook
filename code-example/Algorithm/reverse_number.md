```cpp

int reverse(int x) {
    int rev = 0;
    while (x) {
        rev = rev*10 + x%10;
        x /= 10;
    }
    return rev;
}

int main() {
    int x = 1234560;
    std::cout << reverse(x) << '\n';
}

```
output
```console

654321

```