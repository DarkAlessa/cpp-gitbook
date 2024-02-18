Ref: https://en.cppreference.com/w/cpp/types/integer 
```c++
#include <iostream>
#include <cstdint>        // for uint32_t, uint16, uint32_t, ...
//#include <cinttypes>    // for PRIx8, PRIx16, PRIx32, ... macro 

int main() {
    // (2^n) - 1 : n is number of bit
    // uint8_t n = 0b11111111UL;
    uint8_t  a = 255UL;             // 1-byte (8-bit ) value 0-255
    uint16_t b = 65535UL;           // 2-byte (16-bit) value 0-65535
    uint32_t c = 4294967295UL;      // 4-byte (32-bit) value 0-4294967295
    
    // use unsigned() or +Variable for print unsigned variable
    std::cout << "0x" << hex << uppercase << unsigned(a) <<'\n'; 
    std::cout << "0x" << hex << uppercase << +b <<'\n';
    std::cout << "0x" << hex << uppercase << +c <<'\n';
    std::cout << "-------------"<<'\n';
    std::cout << "sizeof uint8_t  = " << sizeof(uint8_t)  << "-byte\n";
    std::cout << "sizeof uint16_t = " << sizeof(uint16_t) << "-byte\n";
    std::cout << "sizeof uint32_t = " << sizeof(uint32_t) << "-byte\n";
    
    return 0;
}

/* Output
 0xFF
 0xFFFF
 0xFFFFFFFF
 -------------
 sizeof uint8_t  = 1-byte
 sizeof uint16_t = 2-byte
 */
```

Shift Bit
```
  00000001 [1UL << 0UL] = 1UL
  00000010 [1UL << 1UL] = 2UL
  00000100 [1UL << 2UL] = 4UL
  00001000 [1UL << 3UL] = 8UL
  00010000 [1UL << 4UL] = 16UL
  00100000 [1UL << 5UL] = 32UL
  01000000 [1UL << 6UL] = 64UL
  10000000 [1UL << 7UL] = 128UL

  00000010 [2UL << 0UL] = 2UL
  00000100 [2UL << 1UL] = 4UL
  00001000 [2UL << 2UL] = 8UL
  00010000 [2UL << 3UL] = 16UL
  00100000 [2UL << 4UL] = 32UL
  01000000 [2UL << 5UL] = 64UL
  10000000 [2UL << 6UL] = 128UL

  00000011 [3UL << 0UL] = 3UL
  00000110 [3UL << 1UL] = 6UL
  00001100 [3UL << 2UL] = 12UL
  00011000 [3UL << 3UL] = 24UL
  00110000 [3UL << 4UL] = 48UL
  01100000 [3UL << 5UL] = 96UL
  11000000 [3UL << 6UL] = 192UL
```
```c++
#include <iostream>
#include <cstdint>
#include <cinttypes>

int main() {
  uint8_t a = 0UL;	// 0b00000000UL
  uint8_t b = 0UL;	// 0b00000000UL
  
  a |= (1UL << 0UL);						// a = a | (3UL << 0UL);
  std::cout << "0x" << hex << uppercase << +a << '\n';	  // 0x0 (0b00000000) 0UL

  b |= (3UL << 6UL) | (1UL << 4UL);
  std::cout << "0x" << hex << uppercase << +b << '\n';   // 0xD0 (0b11010000) 18UL
  
  return 0;
}
```
