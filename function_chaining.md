```cpp
#include <iostream>
#include <string>

class A {
public:
    A* fx() { 
        std::cout << "Hello x" << "\n";
        return this;
    }

    A* fy() { 
        std::cout << "Hello y" << "\n";
        return this;
    }

    A* fz() { 
        std::cout << "Hello z" << "\n";
        return this;
    }
};

int main() {
    A* a1 = new A();
    a1->fx()->fy()->fz();	// ✔
 // a1->fx().fy().fz(); 	// ❌
    delete a1;

    A a2;
    a2.fx()->fy()->fz();	// ✔
 // a2.fx().fy().fz();		// ❌
}
```

```cpp
#include <iostream>
#include <string>

class A {
public:
    A* fx() { 
        std::cout << "Hello x" << "\n";
        return this;
    }

    A& fy() {		// return reference
        std::cout << "Hello y" << "\n";
        return *this;
    }

    A& fz() { 		// return reference
        std::cout << "Hello z" << "\n";
        return *this;
    }
};

int main() {
    A* a1 = new A();
 // a1->fx()->fy()->fz();	// ❌
    a1->fx()->fy().fz();	// ✔
    a1->fz().fx()->fy();	// ✔
    delete a1;

    A a2;
 // a2.fx()->fy()->fz();	// ❌
    a2.fx()->fy().fz(); 	// ✔
    a2.fz().fx()->fy(); 	// ✔
}
```