Tuple คือ คอลเลกชันของตัวแปรที่มีชนิดเดียวกันหรือต่างกันถือเป็น data structure ชนิดหนึ่งที่ภายในประกอบด้วย elements ที่เป็นลำดับ
หน้าตาของ Tuple [a, b, c] หรือ <a, b, c> หรือ (a, b, c) โดย a, b, c คือ elements ของ Tuple ใน C++ จะใช้ [...]

การสร้าง Tuple ต้องทำการ #include <tuple> เข้ามาก่อน
ตัวอย่าง
...
#include <tuple>
int main() {
	// การสร้าง tuple ทำได้หลายแบบ
  std::tuple<std::string, int> my_name_1 = std::make_tuple("Alice", 24);
  std::tuple<std::string, int> my_name_3 = {"Alice", 24};

  std::tuple<std::string, int> my_name_4; // declaration
  my_name_4 = {"Alice", 24};	// definition

  auto my_name_5 = std::make_tuple("Alice", 24);

  // สร้าง tuple จากตัวแปร
  std::string name = "Alice";
  int age = 24;
  std::tuple<std::string, int> my_name_6;
  my_name_5 = {name, age};
}

การเข้าถึงค่าของ tuple ทำได้ด้วยฟังก์ชั่น get
std::cout << std::get<0>(my_name_1) << '\n'; // output คือ Alice
std::cout << std::get<1>(my_name_1) << '\n'; // output คือ 24
โดย <0> กับ <1> คือ index ที่ใช้เข้าถึงค่าที่อยู่ใน tuple

std::get ยังสามารถเปลี่ยนค่าใน tuple ได้ด้วย
std::get<0>(my_name_2) = "Elsa";
std::get<1>(my_name_2) = 20;
ตอนนี้ my_name_2 มีค่า {"Elsa", 20}

แล้วถ้าเราอยากจะเก็บค่าจาก tuple ไปไว้ในตัวแปรอื่นล่ะ 🤔
เราต้องใช้ฟังก์ชั่น tie ที่สามารถสร้างและแกะ(unpack) tuple แล้วเก็บไว้ในตัวแปรได้
ตัวอย่าง การ unpack 

std::string name;
int age;
std::tie(name, age) = my_name_1;
std::cout << name << '\n';	// output คือ Alice
std::cout << age  << '\n';  // output คือ 24

ประโยชน์ที่สำคัญอย่างหนึ่งของ tuple คือใช้กับฟังก์ชั่นที่ return หลายค่า
ปกติการจะทำแบบนี้ได้เราอาจใช้ struct แต่เราลองมาใช้ tuple ดู 🤩
อันดับแรกเราแค่ประกาศฟังก์ชั่นที่ return เป็น tuple (ง่าย ๆ แบบนี้แหล่ะ)
ตัวอย่าง
...
#include <tuple>
std::tuple<std::string, int> my_name() {
	return {"Alice", 24};
}
int main() {
	std::string name;
	int age;
	std::tie(name, age) = my_name();
	std::cout << name << '\n';	// output คือ Alice
	std::cout << age  << '\n';  // output คือ 24
}

แล้ว Structure binding มันคืออะไร 🤔 เกี่ยวอะไรกับหัวข้อนี้
Structure binding เป็น feature ที่มาใน C++17 ซึ่งสามารถใช้แทน tie() และทำให้ code ดูสะอาดขึ้น
ปกติตอนเราจะเก็บค่าของ tuple เราต้องสร้างตัวแปรแยกไว้ก่อนแล้วใช้ tie() 
...
	std::string name;
	int age;
	std::tie(name, age) = my_name();
...
แต่ Structure binding ทำให้เราทำแบบนี้ได้

auto [name, age] = my_name();	// 😍 นี่มัน modern C++ ของแท้เลยนะเนี้ย

การทำ structure binding ต้องประกาศเป็น auto เท่านั้นเพราะ elements ใน [...] มีชนิดที่ต่างกันได้
structure binding ยังใช้กับ struct ได้ด้วย

ตัวอย่าง 1
struct Num {
	int a = 10;
	int b = 20;
	int c = 30;
};

int main() {
	Num n;
	auto [x, y, z] = n;
	// x = 10, y = 20, z = 30;
}

ตัวอย่าง 2
struct Num {
	static int a, b, c;
};

int Num::a = 10;
int Num::b = 20;
int Num::c = 30;

int main() {
    auto [x, y, z] = std::make_tuple(Num::a, Num::b, Num::c);
    // x = 10, y = 20, z = 30;
}

...

จากที่เล่ามาทั้งหมดมีสิ่งหนึ่งที่ควรรู้คือ make_tuple กับ tie สามารถสร้าง tuple ได้ แต่สิ่งที่ต่างกันคือ tie จะ return ค่าเป็น lvalue reference (&) แปรว่าถ้าตัวแปรถูกแก้ไข tuple ที่สร้างด้วย tie ก็จะถูกเปลี่ยนตามไปด้วย

int main() {
    int a = 10;
    int b = 20;
    
    auto [x, y] = std::make_tuple(a, b);	// สร้าง tuple ด้วย make_tuple
    auto [m, n] = std::tie(a, b);	// // สร้าง tuple ด้วย tie
    
    std::cout << "make_tuple()\t" << ' ' << x << ' ' << y << '\n';
    std::cout << "tie()\t\t\t" << ' ' << m << ' ' << n << '\n';
    
    std::cout << "------------------------" << '\n';
    
    a = 100;
    b = 200;
    
    std::cout << "make_tuple()\t" << ' ' << x << ' ' << y << '\n';
    std::cout << "tie()\t\t\t" << ' ' << m << ' ' << n << '\n';
}

เอาต์พุตจะเป็นแบบนี้
make_tuple()	10 20
tie()			10 20
----------------------------
make_tuple()	10 20
tie()			100 200

สังเกตว่า tuple ที่สร้างด้วย tie จะเปลี่ยนเพราะเป็น reference อารมณ์ประมาณนี้
int& m = a;
int& n = b;
