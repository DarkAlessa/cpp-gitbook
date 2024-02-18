```cpp
class A {
public:
    void setX(int a) { x = a; }
    int getX() const { return x; }
private:
    int x = 0;
};

int main() {
    A a;
    A* apt = &a;
    apt->setX(20);
    std::cout << apt->getX() << '\n';
    
    A* apt2 = new A;
    apt2->setX(40);
    std::cout << apt2->getX() << '\n';
    delete apt2;

    /* การประกาศ pointer ที่ไม่ได้ชี้ไปยัง object ใน memory จริง ๆ จะเกิด Segmentation fault
    A* apt3 = nullptr;
    apt3->setX(40);                    // Segmentation fault , undefined behavior ?
    std::cout << apt3->getX() << '\n'; // Segmentation fault 
    */
}
```