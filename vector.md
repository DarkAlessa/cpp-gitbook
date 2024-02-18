
// An empty vector
   vector<int> v;

// A vector with 5 elements, each an integer
   vector<int> v1(5);

// An array with 5 elements, each of which being an 
// empty vector of integers. Don't confuse this with
// the previous line
   vector<int> v1array[5];

// A vector with 5 elements each having the value 99
   vector<int> v2(5, 99); 

// A vector with the size and values of v2
   vector<int> v3(v2);

// Another, more flexible way to create a vector 
// with the size and values of v2
   vector<int> v4(v2.begin(),v2.end());


// [ 2D Vectors ]

// An empty vector of vectors. The space 
// between the 2 '>' signs is necessary
   vector<vector<int>> v2d;

// If you intend creating many vectors 
// of vectors, the following's tidier
   typedef vector<vector<int>> IntMatrix;
   IntMatrix m;

// Now we'll try to create a 3 by 5 "matrix".
// First, create a vector with 5 elements
   vector<int> v2(5, 99); 

// Now create a vector of 3 elements. 
// Each element is a copy of v2
   vector<vector<int>> v2d2(3,v2);

Ex.1
```cpp
#include <iostream>
#include <vector>

int main() {
    vector<vector<int>> arr;
    for (int i = 0; i < 5; i++) {
        vector<int> v;
        for(int j = 0; j < 5; j++) {
            v.push_back(j);
        }
        arr.push_back(v);
    }
    
    // display 1
    for (const vector<int> &x : arr) {
        for (int y : x) {
            std::cout << y << ' ';
        }
        std::cout << '\n';
    }

    // display 2
    for (size_t i = 0; i < arr.size(); i++) {
        for (int j : arr[i]) {
            std::cout << j << ' ';    
        }
        std::cout << '\n';
    }

    // display 3
    for (size_t n = 0; n < arr.size(); n++) {
        for (size_t m = 0; m < arr[n].size(); m++) {
            std::cout << arr[n][m] << ' ';
        }
        std::cout << '\n';
    }
}
```
---
### pointer
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::vector<int>* vp = &vec;
     
    std::cout << (*vp)[0] << '\n';
    std::cout << (*vp)[1] << '\n';
    std::cout << (*vp)[2] << '\n';
    std::cout << (*vp)[3] << '\n';
    std::cout << (*vp)[4] << '\n';
}
/*
1
2
3
4
5
*/
```