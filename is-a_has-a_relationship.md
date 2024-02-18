/*
Is-A และ Has-A มีประโยชน์ในการออกแบบ class ในการเขียนโปรแกรมแบบ OOP
*/

/* 
1) Is-A Relationship
มี 2 แบบ
object "is a" class
derived class "is a" based class
*/

/*
vehicle "is a" car  ❌
vehicle "is a" boat ❌
car "is a" vehicle	✔
boat "is a" vehicle ✔
เนื่องจาก vechicle มีความทั่วไปมากกว่า car และ boat ดันนั้น vechicle จึงเป็น based class 
ส่วน car กับ boat เป็น derived class
*/
Example 1:
class Vehicle {...};	// based-calss
class Car : public Vehicle {...}; // derived-class
class Boat : public Vehicle {...}; // derived-class

/*
car "is a" lamborghini ❌
car "is a" bugatti ❌
lamborghini "is a" car ✔
bugatti "is a" car ✔
เนื่องจาก lamborghini กับ bugatti มีความเฉพาะเจาะจง lamborghini กับ bugatti จึงควรเป็น object
*/
Example 2:
class Car {...};	// class
int main() {
	Car lamborghini(...);	// object
	Car bugatti(...); // object
}

/*
ใน Example 2 จะเห็นว่า Car กับ lamborghini/bugatti สามารถเป็น derived class "is a" based class ได้
*/
Example 3:
class Car {...};	// based class
class Lamborghini : public Car {...}; // derived-class
class Bugatti : public Car {...}; // derived-class
int main() {
	Lamborghini lamborghini(...); // object
	Bugatti bugatti(...); // object
}

/////////////////////////////////////////////////////////////
/*
2) Has-A Relationship
มี 2 แบบ 
class "has a" data member
class A "has a" Class B

ความสัมพันธ์ที่ใช้ Is-A ไม่ได้จะเป็น Has-A ตัวอย่าง
engine "is a" car ❌
car "is a" engine ❌
student "is a" name ❌
name "is a" student ❌
*/

/*
แบบ class "has a" data member
student "has a" name ✔
student "has a" age ✔
student "has a" id ✔
*/
Example:
class Student {
private:
	string name;
	int age;
	int id;
};

/*
แบบ class A "has a" class B ใช้กับ composition
car "has a" engine ✔
car "has a" whell ✔
car "has a" body ✔
*/
Example:
class Engine {...};
class Whell {...};
class Body {...};

class Car {
public:
    Car() : wheel(new Wheel), engine(new Engine), body(new Body) {}    
private:
    Wheel *wheel;
    Engine *engine;
    Body *body;
};


---
Is-A  ใช้กับ Inheritance
Has-A ใช้กับ Association (Composition and Aggregation)
		Composition ความสัมพันธ์แบบหลวม ๆ เช่น car กับ engine ถ้า car ถูกทำลาย engine ไม่จำเป็นต้องถูกทำลาย
		Aggregation ถ้าไม่มี A ก็จะไม่มี B เช่น มนุษย์ กับ สมอง, หนังสือ กับ หน้ากระดาษ 