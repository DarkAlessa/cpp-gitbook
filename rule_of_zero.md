## Rule of zero
```
คือการที่ใช้ copy/move constructor และ assignment โดย default กรณีไม่ไม่จำเป็นต้องสร้างเอง

```

### แบบ rule of zero
```
ตัวอย่างเนื่องจาก std::string, std::unique_ptr สามารถจักการเรื่องการ move ได้เลยไม่จำเป็นที่จะต้องสร้าง copy/move constructor และ assignment เอง
```
```cpp
class ROZ {
public:
	ROZ(ROZ&& other) = default;				// Move constructor
	ROZ& operator=(ROZ&& other) = default;	// Move assignment operator

private:
	int i{0};
	std::string s{};
	std::unique_ptr<int> p{};
};
```

Example
```cpp
#include <iostream>
#include <string>
#include <utility>  // std::move()
#include <typeinfo> // typeid()
#include <iomanip>  // quoted()

class St {
public:
    std::string getStr() {
        return ss;
    }
private:
    std::string ss{"Hello"};
};

int main() {
    St s1;
    std::cout << std::quoted(s1.getStr()) << '\n';
    
    St s2 = s1;		// copy constructor
    std::cout << std::quoted(s1.getStr()) << '\n';

    St s3 = std::move(s1);	// move constructor
    std::cout << std::quoted(s1.getStr()) << '\n';
}
```
---

### ไม่ใช่  rule of zero
```
เนื่องจากเราใช้ raw pointer (int* p) แสดงว่าเราจำเป็นจะต้องจัดการเอง ในกรณีนี้เราจึงต้องสร้าง copy/move constructor และ assignment เอง
```
Ex1
```cpp
class ROZ {
public:
	ROZ(ROZ&& other) noexcept				// Move constructor
	: i(std::move(other.i))
	, s(std::move(other.s))
	, p(std::move(other.p))
	{				
		other.p = nullptr;
	}

	ROZ& operator=(ROZ&& other) noexcept {	// Move assignment operator
		delete p;		// cleanup
		i = std::move(other.i);
		s = std::move(other.s);
		p = std::move(other.p);
		other.p = nullptr;
		return *this;
	}

private:
	int i{0};
	std::string s{};
	int* p{nullptr};
};

```
Ex2 ใช้ std::exchange()
```cpp
class ROZ {
public:
	ROZ(ROZ&& other) noexcept				// Move constructor
	: i(std::move(other.i))
	, s(std::move(other.s))
	, p(std::exchange(other.p, nullptr))
	{				
	}

	ROZ& operator=(ROZ&& other) noexcept {	// Move assignment operator
		delete p;		// cleanup
		i = std::move(other.i);
		s = std::move(other.s);
		p = std::exchange(other.p, nullptr);
		return *this;
	}

private:
	int i{0};
	std::string s{};
	int* p{nullptr};
};

```