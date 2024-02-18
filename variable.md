## Variable Assignment
```
1) Copy Assignment
	int width; // define
	width = 5; // copy assignment of value 5 into variable width

2) Copy and Direct Initialization
	int width = 5; // copy initialization of value 5 into variable width
	int width(5);	// direct initialization of value 5 into variable width

3) Brace Initialization
	int width{5};	// direct brace initialization of value 5 into variable width (preferred)
	int height = { 6 }; // copy brace initialization of value 6 into variable height 
```

Ex
```cpp
int x(10)	// = 	int x = 10
int x{10}	// =	int x = {10}

int x(2.5);	// output = 2 because "int"
int x{2.5};	// output : error: narrowing conversion of ‘2.5e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]
```
---
## Type Casting
```
C++ is a strong-typed language. Many conversions, specially those that imply a different interpretation of the value, require an explicit conversion, known in C++ as type-casting. There exist two main syntaxes for generic type-casting: functional and c-like:
```
Ex
```cpp
double x = 10.3;
int y;
y = int(x);    // functional notation
y = (int)x;    // c-like cast notation
```