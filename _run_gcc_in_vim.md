example: main.cpp
```
	:!clear && g++ -std=c++20 -O2 -Wall -Wpedantic % -o %< && %<.exe<CR>
```
มีค่าเท่ากับ
```
	:!clear && g++ -std=c++20 -O2 -Wall -Wpedantic main.cpp -o main && main.exe<CR>
```

อธิบาย
```
%  	 = ชื่อไฟล์
%< 	 = ไฟล์ไม่มีนามสกุล (main.cpp -> main)
<CR> = สั่งให้กด Exter เพื่อรันคำสั่ง

⚠ระวัง⚠
ถ้ามีไฟล์ .cpp หลายไฟล์จะไม่สามารถใช้ % และ %< ได้ ควรใช้
	:!clear && g++ -std=c++20 -O2 -Wall -Wpedantic *.cpp -o output && output.exe<CR>

```

ข้อมูลเพิ่มเติม Vim help
```vim
:h filename-modifiers
```