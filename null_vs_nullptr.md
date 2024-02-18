`NULL` คือ `(void*)0`
```cpp
int a  = NULL;	// warning: converting to non-pointer type 'int' from NULL
int* b = NULL;	// Implicit conversion from void* to int*
```
---
ปัญหาของ NULL
```cpp
void foo(int a) { cout << "int a" << endl; }
void foo(int* a) { cout << "int* a" << endl; }
  
int main() {
    foo(NULL); // function ไหนจะถูกเรียก ❓
}

/* error output */
main.cpp: In function 'int main()':
main.cpp:10:8: error: call of overloaded 'foo(NULL)' is ambiguous
main.cpp:4:6: note: candidate: 'void foo(int)'
main.cpp:5:6: note: candidate: 'void foo(int*)'
```
---
`nullptr (since C++11)`
	เป็น pointer literal เป็นค่า prvalue ของประเภท std::nullptr_t มีการแปลงโดยนัยจากค่า nullptr 
	เป็นค่าตัวชี้ null ของตัวชี้ประเภทใด ๆ และตัวชี้ใด ๆ ไปยังประเภทสมาชิก

ตัวอย่าง 1
```cpp
int* a = nullptr;
```
ตัวอย่าง 2
```cpp
void foo(int a)		{ cout << "int a"  << endl; 	}
void foo(int* a)	{ cout << "int* a" << endl; }
  
int main() {
    foo(nullptr); // foo(int* a) จะถูกเรียก
}
```
---
`std::nullptr_t`
	the type of the null pointer literal, nullptr.

ตัวอย่าง 1
```cpp
void foo(int* a) 			{ cout << "int* a" << endl; 			}
void foo(double* a) 		{ cout << "double* a" << endl;			}
void foo(std::nullptr_t a)	{ cout << "std::nullptr_t a" << endl;	}
  
int main() {
    int* 	m = nullptr;
    double* n = nullptr;

    foo(m);  		// foo(int* a) จะถูกเรียก
    foo(n);  		// foo(double* a) จะถูกเรียก
    foo(nullptr);	// foo(std::nullptr_t a) จะถูกเรียก
    // foo(NULL);	// ambiguous overload: all three functions are candidates
}
```