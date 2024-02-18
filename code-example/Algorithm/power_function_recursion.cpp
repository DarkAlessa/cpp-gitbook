/*
When pow(x, n) is called, the execution splits into two branches

              if n==1  = x
             /
pow(x, n) =
             \
              else     = x * pow(x, n - 1)

For example, to calculate pow(2, 4) the recursive variant does these steps:

1) pow(2, 4) = 2 * pow(2, 3)
2) pow(2, 3) = 2 * pow(2, 2)
3) pow(2, 2) = 2 * pow(2, 1)
4) pow(2, 1) = 2

*/

//------------------------------------------------------

#include <iostream>

size_t pow(int x, int n) {
  return (n == 1) ? x : (x * pow(x, n - 1));
}

int main() {
    size_t a = pow(2, 3);
    std::cout << a;
}

//------------------------------------------------------
// std::function
#include <functional>

int main() {
    const std::function<int(int,int)> pow = [&pow](int x, int n) {
        return (n == 1) ? x : (x * pow(x, n - 1));
    };

    std::cout << pow(2, 3) << '\n';
} 