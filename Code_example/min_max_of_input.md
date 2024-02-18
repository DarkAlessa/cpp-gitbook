#include <iostream>
using namespace std;

int main()
{
    int min = 0;
    int max = 0;
    int n = 0, b;
    cin >> n;	// จำนวน input
    for(int i = 0; i < n; i++) {
        cin >> b;
        if(b < min) min = b;
        if(b > max) max = b;
    }
    cout<<"min = "<< min <<'\n';
    cout<<"max = "<< max <<'\n';

    return 0;
}