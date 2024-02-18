```c++
int main() {
	// unsync C/C++ I/O streams
	std::ios_base::sync_with_stdio(false);

	// unties cin from cout
	std::cin.tie(nullptr);

	/* code here */
}
```
```c++
int main() {
	(*std::cin.tie(nullptr)).sync_with_stdio(false);

	/* code here */
}
```
```c++
int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);

	/* code here */
}
```
---
example
```c++

int  main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    std::vector<int> vec(n);

    for (auto& i : vec) {
        std::cin >> i;
    }

    std::cout << "\n-------------------\n";
    for (auto& i : vec) {
        std::cout << i << " " ;
    }
    std::cout << "\n-------------------\n";
}

```
output
```console
4
100
200
300
400
Enter number:
-------------------
100 200 300 400
-------------------
```
