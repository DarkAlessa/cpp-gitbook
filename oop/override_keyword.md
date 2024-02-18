override ใช้เพื่อยืนยันว่าฟังก์ชั้นที่ทำการ overriding นั้นเป็น virtual function 
โดยจะต้องมี ชื่อ พารามิเตอร์ return-type เดียวกัน

///////////////////////////////////////////////////////
struct A {
    virtual void f() { cout << "from A\n"; }
};

struct B : A {
    void f(int a) override {}	// Error ทำการ override แต่ฟังก์ชั้น B::f(int a) ไม่ตรงกับ A::f()
    int f() { return 0; }		// Error
    void f(int a) { cout << "Overloading?\n"; }   // ไม่ใช่ Overloading เป็นคนละฟังก์ชั่นกันซึ่งจะซ่อน void A::f() เพราะไม่สามารถ overloading ข้าม scope ได้
	/* กรณีที่ต้องการทำ Overloading
	   using A::f;
	   void f(int a) { cout << "Overloading\n"; };
	*/
    void f() override { cout << "from B\n"; }	// Ok

/* หมายเหตุ**
    void f() override {} 
    มีค่าเท่ากับ
    void f() {} // ไม่มี override keyword (override keyword เป็น option)
*/
};