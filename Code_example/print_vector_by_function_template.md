#include <iostream>
#include <vector>
using namespace std;

// type alias
using vt2D_int    = vector<vector<int>>;
using vt2D_foat   = vector<vector<float>>;
using vt2D_double = vector<vector<double>>;

template <typename T>
void vt_print(const vector<vector<T>>& vec) {
    for(const vector<T>& x : vec) {
        for(T y : x){
            cout << y << ' ';
        }
        cout << "\n";
    }
}

int main() {
    vt2D_int vec1{{1,2,3},    // vec1[0]
                  {4,5,6},    // vec1[1]
                  {7,8,9}};   // vec1[2]
    vt2D_foat vec2{{1.1,2.2,3.3},    // vec2[0]
                   {4.1,5.2,6.3},    // vec2[1]
                   {7.1,8.2,9.3}};   // vec2[2]
                             
    vt_print<int>(vec1);
    vt_print<float>(vec2);

    return 0;
}
/*
1 2 3 
4 5 6 
7 8 9 
1.1 2.2 3.3 
4.1 5.2 6.3 
7.1 8.2 9.3 
*/