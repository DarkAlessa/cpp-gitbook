### การเข้าถึง data member และ member function ด้วย scope resolution สมาชิกของ class ต้องเป็น static
```cpp
class X {
public:
    static int a;	            // ไม่สามารถ initialization ได้
    inline static int b = 20;   // OK (since C++17)
    const static int c = 30;    // OK
    const static int d;         // OK
    int e = 40;
    enum { zero, one ,two };
};

int X::a = 10;          // definition (does not use 'static')
const int X::d = 20;    // definition (does not use 'static')

int main() {
    int a = X::a;		// OK
    int b = X::b;		// OK
    int c = X::c;		// OK
    int d = X::d;       // OK
    int e = X::e;       // Error เพราะ e ไม่ใช่ static
    int f = X::one;     // OK
}
```
```cpp
class X {
public:
    static std::string ss(std::string&& s) {
        return s;
    }
};

int main() {
    std::string a = X::ss("Hello");
    std::cout << a << '\n';
}
/* Output
Hello
*/
```