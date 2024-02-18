1) Normal constructor

class Time {
public:
	Time(int h, int m, int s) {
		if((0 <= h && h <= 23) &&
		   (0 <= m && m <= 59) &&
		   (0 <= s && s <= 59)) {
			hour = h;
			minute = m;
			second = s;
		}
	}
private:
	int hour;
	int minute;
	int second;
};

////////////////////////////////////////////////////////////////

2) Member-initializer list

class Time {
public:
	Time(int h, int m, int s) 
		: hour(h), minute(m), second(s) {}
private:
	int hour;
	int minute;
	int second;
};

////////////////////////////////////////////////////////////////

3) Constructor overloading
	- constructor ชื่อเดียวกัน parameters ต่างกัน

class Time {
public:
	Time() : hour(0), minute(0), second(0) {}
	Time(int h) : hour(h), minute(0), second(0) {}
	Time(int h, int m) : hour(h), minute(m), second(0) {}
	Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
private:
	int hour;
	int minute;
	int second;
};

////////////////////////////////////////////////////////////////

4) Default arguments
	- กำหนดค่าเริ่มต้นให้ parameters 
	- argument ที่ไม่ได้กำหนดจะเป็นค่า default

class Time {
public:
	Time(int h = 0, int m = 0, int s = 0)
		: hour(h), minute(m), second(s) {}
private:
	int hour;
	int minute;
	int second;
};

Time t1;			// h = 0, m = 0, s = 0
Time t2(5);			// h = 5, m = 0, s = 0
Time t3(5, 30);		// h = 5, m = 30, s = 0
Time t4(5, 30, 10);	// h = 5, m = 30, s = 10

/*
 ถ้าต้องการให้มีอย่างน้อย 1 argument ไม่ต้องเซีตค่า default โดย
 ต้องเริ่มจาก parameter ตัวแรก(ซ้าย->ขวา) เพราะถ้าเป็น parameter
 ตัวสุดท้าย argument ของ object จะไม่สมเหตุสมผล

 	Time(int h, int m = 0, int s)			// ❌ error
		: hour(h), minute(m), second(s) {}

 	Time t1(,,10); // 🤔❓
 */

class Time {
public:
	Time(int h, int m = 0, int s = 0)		// ok
		: hour(h), minute(m), second(s) {}
private:
	int hour;
	int minute;
	int second;
};

Time t1;			// ❌ error
Time t2(5);			// h = 5, m = 0, s = 0
Time t3(5, 30);		// h = 5, m = 30, s = 0
Time t4(5, 30, 10);	// h = 5, m = 30, s = 10

////////////////////////////////////////////////////////////////

5) Delegating constructors
	- เรียกใช้ constructor อื่น
	- มักเรียกใช้ constructor ที่มี parameter มากสุด

class Time {
public:
	Time() : Time(0,0,0) {}
	Time(int h) : Time(h,0,0) {}
	Time(int h, int y) : Time(h,y,0) {}
	Time(int h, int m, int s) {
		if((0 <= h && h <= 23) &&
		   (0 <= m && m <= 59) &&
		   (0 <= s && s <= 59)) {
			hour = h;
			minute = m;
			second = s;
		}
	}
private:
	int hour;
	int minute;
	int second;
};

✅	delegating constructors ดีกว่า constructor overloading ตรงที่
	เมื่อต้องการแก้ไขก็ไม่จำเป็นตองแก้ไขทุกๆ constructor 
