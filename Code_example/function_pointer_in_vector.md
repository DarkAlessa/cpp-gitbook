/////// Version 1
#include <iostream>
#include <vector>

class Apple {
public:
    std::vector<void (*)()> m_fnPointers;
};

class Banana {
public:
    static void startApp() { std::cout << "Start App" << '\n'; };
    static void stopApp() { std::cout << "Stop App" << '\n'; };
};

int main()
{
    Apple apple;
    Banana banana;
    apple.m_fnPointers.push_back(banana.startApp);
    apple.m_fnPointers.push_back(banana.stopApp);
    (apple.m_fnPointers[0])();     	// (*apple.m_fnPointers[0])();
    (apple.m_fnPointers[1])();		// (*apple.m_fnPointers[1])();
    return 0;
}

/////// Version 2
#include <iostream>
#include <vector>

class Apple {
public:
    std::vector<void (*)()> m_fnPointers;
    void addPtr(void (*foo)()) {
        m_fnPointers.push_back(foo);
    }
};

class Banana {
public:
    static void startApp() { std::cout << "Start App" << '\n'; };
    static void stopApp() { std::cout << "Stop App" << '\n'; };
};

int main()
{
    Apple apple;
    Banana banana;
    apple.addPtr(banana.startApp);
    apple.addPtr(banana.stopApp);
    (apple.m_fnPointers[0])();     	// (*apple.m_fnPointers[0])();
    (apple.m_fnPointers[1])();		// (*apple.m_fnPointers[1])();

    return 0;
}