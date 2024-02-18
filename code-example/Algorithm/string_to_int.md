char to int
```cpp
int main() {
	const char* c = "1234567890";
	int num = c[2] - '0';
	std::cout << num << '\n';

	// ascii 
	// char 0 = 48 Dec
	// char 3 = 51 Dec
}
```

int to char
```cpp
int main() {
	int num = 3;
	char c = num + '0';
}
```