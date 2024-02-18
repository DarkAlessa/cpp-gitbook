`Object Delegation` คือการใช้ object ของคลาส A ในคลาส B

```cpp
class A {
public:
	void fn() { std::cout << "Hello" << '\n'; }
};

class B {
public:
	a.fn();	// delegation
private:
	A a;
};
```