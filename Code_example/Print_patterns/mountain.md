```cpp
#include <iostream>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int input;
  int max = 0;
  std::cin >> input;
  int height[input];

  for (int i = 0; i < input; ++i) {
    std::cin >> height[i];
    if (height[i] >= max) max = height[i];
  }

  for (int i = 0; i < max; ++i) {
    for (int j = 0; j < input; ++j) {
      for (int k = 0; k < height[j]; ++k)      std::cout << (i + k == max - 1 ? "/"  : " ");
      for (int k = height[j] - 1; k >= 0; --k) std::cout << (i + k == max - 1 ? "\\" : " ");
    }
    std::cout << "\n";
  }
}

```

input
```
6
1 3 2 6 5 4
```
output
```
                 /\
                /  \        /\
               /    \      /  \      /\
    /\        /      \    /    \    /  \
   /  \  /\  /        \  /      \  /    \
/\/    \/  \/          \/        \/      \
```