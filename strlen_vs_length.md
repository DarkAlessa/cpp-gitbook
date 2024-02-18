### การหาความยาว string
```
strlen() ใช้กับ array ของ char หรือ string ใน C (ที่มี '\0' ลงท้ายแต่จะไม่นับ '\0')
.length() ใช้กับ string ใน C++
```
```cpp
#include<iostream>
#include<string>
#include<cstring>		// for c_str()

int main() {
    const string& str1 = "Hello";		// Cpp-style
    const char* str2 = "Hello";			// C-style
    char c[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    int s1 = str1.length();
    int s2 = strlen(str1.c_str());	// strlen() for C-style ต้องแปลงเป็น C-style
    int s3 = strlen(str2);
    int s4 = strlen(c);
    
    std::cout << s1 << '\n';
    std::cout << s2 << '\n';
    std::cout << s3 << '\n';
    std::cout << s4 << '\n';
}

/* Output
5
5
5
5
*/
```