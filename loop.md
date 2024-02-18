```cpp
if(x){} // True if x = 1 เท่ากับ if(x == 1){}
if(!x)[] // True if x = 0 เท่ากับ if(x == 0){}


// Range Base Loop
int a[2] = {1,2};
for (const int& i : a) {
	std::cout << i << '\n';
}
```