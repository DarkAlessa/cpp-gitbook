#include <iostream>
#include <string>
#include <vector>
using namespace std;

class X {
  public:
    void m() {
        cout << "Class X" << endl;
    }
};

class Y : public X {
  public:
    void m() {
        cout << "Class Y" << endl;
    }
};

int main()
{
    Y y;
    y.m();      // Class Y
    y.X::m();   // Class X
    return 0;
}
