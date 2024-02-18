#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Animal {
    public:
        Animal() : name("No Name") {}
        Animal(const string& name) : name(name) {}
        virtual void getSound() const { cout << "Animal sound" << endl; }
        void getName() const { cout << name << endl; }
        
    private:
        string name;
};

class Dog : public Animal {
    public:
        Dog() = default;
        Dog(const string& name) : Animal(name) {}
        void getSound() const { cout << "Dog sound" << endl; }
};
class Cat : public Animal {
    public:
        Cat() = default;
        Cat(const string& name) : Animal(name) {}
        void getSound() const { cout << "Cat sound" << endl; }
};

int main() {
    Animal* animal = new Dog;
    animal->getSound();
    animal = new Cat;
    animal->getSound();
    return 0;
}