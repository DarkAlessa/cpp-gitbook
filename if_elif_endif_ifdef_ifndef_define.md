```
#ifdef  identifier	เท่ากับ #if defined identifier		หรือ	#if defined( identifier )
#ifndef identifier	เท่ากับ #if !defined identifier	หรือ	#if !defined( identifier )
```
```cpp

#ifndef PATTY
#define PATTY 10
    #if defined LISA
        #define SS "My name is Lisa"
    #elif defined PATTY && PATTY == 10
        #define SS "My name is Patty"
    #endif
#endif

#if !defined( LISA )
#define LISA
    #if defined LISA
        #define LL "My name is Lisa"
    #endif
#endif

int main() {
    std::cout << SS << '\n';
    std::cout << LL << '\n';
}

/* Output
My name is Patty
My name is Lisa
*/

```
```cpp

#ifndef PATTY
#define PATTY 10
#   if defined LISA
#       define SS "My name is Lisa"
#   elif defined PATTY && PATTY == 10
#       define SS "My name is Patty"
#   endif
#endif

#if !defined( LISA )
#define LISA
#   if defined LISA
#       define LL "My name is Lisa"
#   endif
#endif

```
```cpp
#ifdef _WIN32
    #ifdef _WIN64
        std::cout << "Win64" << '\n';
    #else
        std::cout << "Win32" << '\n';
    #endif
#elif __APPLE__
    std::cout << "Apple" << '\n';
#endif
```