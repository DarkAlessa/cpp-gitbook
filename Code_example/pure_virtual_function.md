#include <iostream>
#include <string>

// Pure Virtual Function
// เมื่อ function member เป็น pure virtual function จะทำให้คลาสกลายเป็น Abstrac class
// Abstrac class ไม่สามารถสร้าง object ได้

class Pet {
    public:
        Pet() { name = "No name!"; }
        Pet(std::string name, int age) : name(name), age(age) {}
        void getProperties() const { std::cout << "Name : " << name << "\tAge : " << age << std::endl; }
        virtual void makeSound() const = 0;	// pure virtual function
    private:
        std::string name;
        int age;
};

class Dog : public Pet {
    public:
        Dog() : Pet() {}
        Dog(std::string name, int age) : Pet(name, age) {}
        void makeSound() const { std::cout <<"Hong Hong !!" << std::endl; }
};

class Cat : public Pet {
    public:
        Cat() : Pet() {}
        Cat(std::string name, int age) : Pet(name, age) {}
};

int main() {
    Dog dog("Pubpy", 2);
    Pet pet;     			// สร้าง object ไม่ได้เพราะเป็น Abstrac class
    Cat cat;			// สร้าง object ไม่ได้ Cat ถือเป็น Abstrac class เพราะยังไม่ imprement pure virtual function
    Pet* pet = new Cat("Kitty", 1);	// Abstrac class สร้าง pointer ได้
    dog.makeSound();	// ไม่เกิด dynamic binding
    pet->makeSound();	// เกิด dynamic binding
    return 0;
}