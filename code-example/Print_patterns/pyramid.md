```cpp
int main() {
    int rows = 5;

    for (int i = 1; i <= rows; i++) {
        // Print spaces before the numbers
        for (int j = 1; j <= rows - i; j++) {
            std::cout << "-";
        }

        // Print numbers in increasing order
        for (int k = 1; k <= i; k++) {
            std::cout << k;
        }

        // Print numbers in decreasing order
        for (int l = i - 1; l >= 1; l--) {
            std::cout << l;
        }

        // Move to the next line after each row
        std::cout << std::endl;
    }
}
```

output
```console
----1
---121
--12321
-1234321
123454321
```