drawing area จะไม่วาดใหม่จนกว่าจะเรียก queue_draw() ในตัวอย่างคือการสั่งให้วาดใหม่ทุก 1 วินาที

```cpp

My_Area::My_Area() {
	Glib::signal_timeout().connect(sigc::mem_fun(*this, &My_Area::on_timeout), 1000); // millisecond
	set_draw_func(sigc::mem_fun(*this, &My_Area::on_draw));
}

My_Area::~My_Area() noexcept {}

void My_Area::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
	/*
		cairo code here
	*/
}

bool My_Area::on_timeout() {
	queue_draw();	// บังคับให้วาดใหม่และเรียก slot อีกครั้ง
	return true;
}
```