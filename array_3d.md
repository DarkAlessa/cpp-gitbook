```cpp
int main() {
    int arr[2][3][2] = {
        {
         {1,2},
         {3,4},
         {5,6}
        },
        {
         {1,2},
         {3,4},
         {5,6}
        }
      };

    /*
    std::cout << sizeof(arr)/sizeof(*arr) << '\n';
    std::cout << sizeof(arr)/sizeof(**arr) << '\n';
    std::cout << sizeof(arr)/sizeof(***arr) << '\n';
    */
    
    for (auto x : reinterpret_cast<int (&)[2*3*2]>(arr)) {
        std::cout << x << ", ";
    }
    
    std::cout << "\n-------------------------------------\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                std::cout << arr[i][j][k] << ", ";
            }
            std::cout << '\n';
        }
        std::cout << "------\n";
    }
}

/* output
1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 
-------------------------------------
1, 2, 
3, 4, 
5, 6, 
------
1, 2, 
3, 4, 
5, 6, 
------
*/
```