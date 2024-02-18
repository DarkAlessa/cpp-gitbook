```text
คำสั่ง strip ลดขนาดของอ็อบเจกต์ไฟล์ XCOFF
คำสั่ง strip เลือกที่จะลบ 
- line number information 
- relocation information
- debug section
- typchk section
- comment section
- file headers
และตารางสัญลักษณ์(symbol table)ทั้งหมดหรือบางส่วนออกจากไฟล์อ็อบเจ็กต์ XCOFF เมื่อคุณใช้คำสั่งนี้ การดีบักสัญลักษณ์ของไฟล์จะทำได้ยาก ดังนั้น ⚠ ควรใช้คำสั่ง strip กับโปรแกรมที่ผ่านการ debug แล้วเท่านั้น
```

```console

gcc main.cpp -o release

strip --strip-debug release.exe

```

before strip
```console
drwxr-xr-x 1 nuker nuker      0 Jul  8 21:34 .
drwxr-xr-x 1 nuker nuker      0 Jul  8 21:44 ..
-rw-r--r-- 1 nuker nuker    217 Jun 25 12:26 main.cpp
-rwxr-xr-x 1 nuker nuker 134714 Jul  8 21:53 release.exe
```

เมือทำการ strip แล้ว ไฟล์ release.exe จะมีขนาดเล็กลง
```console
drwxr-xr-x 1 nuker nuker     0 Jul  8 21:44 .
drwxr-xr-x 1 nuker nuker     0 Jul  8 21:44 ..
-rw-r--r-- 1 nuker nuker   217 Jun 25 12:26 main.cpp
-rwxr-xr-x 1 nuker nuker 49644 Jul  8 21:53 release.exe
```