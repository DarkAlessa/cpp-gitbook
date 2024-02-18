```
FPS คืด frame per second
	60 FPS = 60 frame/s

Delta Time คือ จากจุดเริ่มต้นจนถึงสิ้นสุด
	start;
		// code here
		// code here
	end;
	delta_time = end - start;

Frame Time คือ ระยะเวลาที่ใช้ใน 1 frame
	เช่น frame_time = 1000 / 60 = 16.6667 ms
	หรือ frame_time = 1 / 60    = 0.0167  s

ซึ่งหมายความว่าเพื่อรักษาอัตราเฟรมที่สม่ำเสมอที่ 60 เฟรมต่อวินาที คุณต้องทำการคำนวณ การเรนเดอร์ และตรรกะของเกมที่จำเป็นทั้งหมดให้เสร็จสิ้นภายใน 0.0167 วินาทีสำหรับแต่ละเฟรม

while (true) {
	start;   ----+---------------------+
	// code      |                     |
	// code      |delta_time           |
	// code      |                     |frame_time
	end;     ----+                     |
	delay(frame_time - delta_time); ---+
}

```

### SDL_GetTicks()
```cpp

const int FPS = 60;
const int frame_time = 1000 / FPS;

Uint32 start;
Uint32 delta_time;

start = SDL_GetTicks(); // Get the current time in milliseconds at the start of the frame
//---------------------------
// game loop	(1 loop คือ 1 frame)
//---------------------------
delta_time = SDL_GetTicks() - start;
if (frame_time > delta_time) {
	SDL_Delay(frame_time - delta_time);
}

```

### SDL_GetTicks64()
```cpp

const int FPS = 60;
const int frame_time = 1000 / FPS;

Uint64 start;
Uint64 delta_time;

start = SDL_GetTicks64(); // Get the current time in milliseconds at the start of the frame
//---------------------------
// game loop	(1 loop คือ 1 frame)
//---------------------------
delta_time = SDL_GetTicks64() - start;
if (frame_time > delta_time) {
	SDL_Delay(frame_time - delta_time);
}

```
