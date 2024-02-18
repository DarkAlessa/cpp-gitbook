```
sizof(int)	// 4-byte = 32-bit
		-(2^(N-1)) to (2^(N-1) - 1)
		-(2^(32-1)) to (2^(32-1) - 1)
		-(2^(31)) to (2^(31)-1)
		-2147483648 ot 2147483647
		

int x = 4;
int y = ~x;
// y = -5

solve

4	0100	
~4	1011		negative (1) take 2's complement -----+
	0100		1's complement                        |
	0100 + 1	2's complement			              |
	0101		= -5 <--------------------------------+
```