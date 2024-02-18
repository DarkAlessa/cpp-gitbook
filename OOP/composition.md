/*
Composition จะตรงข้ามกับ Inheritance โดยจะเป็นแบบ Has-A relationship
เป็นการนำเอาองค์ประกอบ (composition) มารวมกันเป็นคลาส เช่น

car has-a wheels
car has-a engine
car has-a body
*/

class Wheel {
    public:
     void print() const { cout << "Class Wheel" << endl; }
};

class Engine {
    public:
     void print() const { cout << "Class Engine" << endl; }
};

class CarBody {
    public:
     void print() const { cout << "Class CarBody" << endl; }
};

class Car {
public:
    Car() : wheel(new Wheel), engine(new Engine), carbody(new CarBody) {}
    void getVar() {
        wheel->print();
        engine->print();
        carbody->print();
    }
    
private:
    Wheel *wheel;
    Engine *engine;
    CarBody *carbody;
};

int main() {
    Car car;
    car.getVar();
    return 0;
}

//--------------------------------------
class A {
public:
    void setX(int a) { x = a; }
    int getX() const { return x; }
    
private:
    int x = 0;
};

class Comp {
public:
    Comp() = default;
    Comp(int x) : a(new A) { a->setX(x); };
    ~Comp() { delete a; }
    int getVar() { return a->getX(); };
    
private:
    A* a;
};


int main() {
    Comp c(10);
    c.getVar();
    std::cout << c.getVar();
}