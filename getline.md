```cpp
#include <iostream>
#include <string>

int main() {
	std::string name;
	int age;

	std::cout << "What's your age? : ";
	std::cin >> age;	// ❌ เมือกด enter std::getline จะรับ '\n' เข้าไปใน buffer ด้วย 

	// ใช้ std::ws เพือไม่ให้ std::getline รับ '\n' หรือ whitespace เข้ามา ✔
	std::cout << "What's your name? : ";
	std::getline(std::cin >> std::ws, name);

	std::cout << "Hello "   << name << '\n';
	std::cout << "You are " << age  << '\n';
}
```
```cpp
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

int main() {
    std::string ss;
    std::istringstream a{"    Hello"};
    std::getline(a >> std::ws, ss);
    std::cout << ss;
}

/*
Hello
*/
```