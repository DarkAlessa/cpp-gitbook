#include<iostream>
using namespace std;

int main()
{
    int max;
    cout << "Max loop : ", cin >> max;
    
    for(int i = 1; i <= max; i++) {
        for(int j = 1; j <= i; j++) {
            cout << (2*j-1) << " - ";
        }
        // backspace 2 positions and replace with " "
        cout << "\b\b" << " ";
        cout << '\n';
    }
}

   /* Output
    Max loop : 5
    1
    1 - 3
    1 - 3 - 5
    1 - 3 - 5 - 7
    1 - 3 - 5 - 7 - 9
    */