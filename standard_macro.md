```
C89	    __STDC__	                ANSI X3.159-1989
C90	    __STDC__	                ISO/IEC 9899:1990
C94	    __STDC_VERSION__ = 199409L	ISO/IEC 9899-1:1994
C99	    __STDC_VERSION__ = 199901L	ISO/IEC 9899:1999
C11	    __STDC_VERSION__ = 201112L	ISO/IEC 9899:2011
C18	    __STDC_VERSION__ = 201710L	ISO/IEC 9899:2018
C++98	__cplusplus = 199711L	    ISO/IEC 14882:1998
C++11	__cplusplus = 201103L	    ISO/IEC 14882:2011
C++14	__cplusplus = 201402L	    ISO/IEC 14882:2014
C++17	__cplusplus = 201703L	    ISO/IEC 14882:2017
C++20   __cplusplus = 202002L		ISO/IEC 14882:2020
C++23   __cplusplus = 202302L	    ISO/IEC 14882:2023
C++/CLI	__cplusplus_cli = 200406L	ECMA-372
DSP-C	                            ISO/IEC JTC1/SC22 WG14/N854
EC++	__embedded_cplusplus	    Embedded C++
```

```cpp
#if __STDC_HOSTED__ != 1
#   error "Not a hosted implementation"
#endif
 
#if __cplusplus >= 202302L
#   warning "Using #warning as a standard feature"
#endif
 
#include <iostream>
 
int main() {
    std::cout << __cplusplus << '\n';
    std::cout << "The implementation used is hosted\n";
}
```