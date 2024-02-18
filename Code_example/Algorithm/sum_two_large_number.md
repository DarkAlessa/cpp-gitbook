```cpp
int main() {
    const int numDigits = 50;

    // Input the numbers as constant character pointers
    const char* number1 = "12345678901234567890123456789012345678901234567890";
    const char* number2 = "98765432109876543210987654321098765432109876543210";

    // Perform digit-wise addition and store the result
    char result[numDigits + 1]; // +1 for the potential carry at the end
    int carry = 0;
    for (int i = numDigits - 1; i >= 0; i--) {
        int digit1 = number1[i] - '0';
        int digit2 = number2[i] - '0';
        int sum = digit1 + digit2 + carry;
        result[i + 1] = (sum % 10) + '0';
        carry = sum / 10;
    }
    result[0] = carry + '0'; // Store the potential carry in the first position

    // Output the sum
    std::cout << "Sum: ";
    if (carry != 0) {
        std::cout << result[0];
    }
    for (int i = 1; i <= numDigits; i++) {
        std::cout << result[i];
    }
    std::cout << std::endl;
}
/* Output
    Sum: 111111111011111111101111111110111111111011111111100
*/
```

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

auto main() -> int {
    std::string s1 = "123456789";
    std::string s2 = "54321";

    int carry = 0;
    int sum, d1, d2;
    std::string result;
    size_t max = std::max(s1.size(), s2.size());

    for (size_t i = 0; i < max; i++) {
        i < s1.size() ? (d1 = s1[s1.size() - 1 - i] - '0') : (d1 = 0);
        i < s2.size() ? (d2 = s2[s2.size() - 1 - i] - '0') : (d2 = 0);

        sum = d1 + d2 + carry;
        result.insert(result.begin(), (sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry != 0) result.insert(result.begin(), carry + '0');

    std::cout << result << '\n';
}

/* Output
    123511110
*/
```

### Fibonacci number
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string add_large_numer(const std::string& s1, const std::string& s2) {
    int carry = 0;
    int sum, d1, d2;
    std::string result;
    size_t max = std::max(s1.size(), s2.size());

    for (size_t i = 0; i < max; i++) {
        i < s1.size() ? (d1 = s1[s1.size() - 1 - i] - '0') : (d1 = 0);
        i < s2.size() ? (d2 = s2[s2.size() - 1 - i] - '0') : (d2 = 0);

        sum = d1 + d2 + carry;
        result.insert(result.begin(), (sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry != 0) result.insert(result.begin(), carry + '0');
    return result;
}

auto main() -> int {
    int loop = 1000;

    std::vector<std::string> v{"0", "1"};
    for (int i = 2; i < loop; i++) {
        v.emplace_back(add_large_numer(v[i-1], v[i-2]));
    }
    
    for (const auto& i : v) {
        std::cout << i << '\n';
    }
}
```