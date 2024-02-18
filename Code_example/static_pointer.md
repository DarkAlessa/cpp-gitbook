#include <iostream>
using namespace std;

void foo() {
    int a = 10;
    int b = 20;
    static int* ptr = nullptr; // static pointer
    if(!ptr) {
        ptr = &a;
    } else { 
        ptr = &b;
    }
    cout << *ptr << endl;
}

int main() {
    foo();
    foo();
}

// Output
/* แบบไม่มี static
10
10
*/

/* แบบมี static 
10
20
*/
