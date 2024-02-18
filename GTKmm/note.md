- แอปพลิเคชัน gtkmm ประกอบด้วย `window` ที่ข้างในมี `widget`
- widget ถูกจัดเรียงภายใน `container` วิดเจ็ต
- มี widget ที่มองเห็นได้และ widget ที่ไม่สามารถมองเห็นได้ วิดเจ็ตเหล่านี้มีไว้เพื่อจัดเรียงวิดเจ็ตอื่นๆ เท่านั้น

### Single-item Containers
วิดเจ็ตคอนเทนเนอร์รายการเดียวส่วนใหญ่มีเมธอด set_child() และ unset_child() สำหรับวิดเจ็ตลูก
```
- Gtk::Button
- Gtk::Window
- Gtk::Frame
- Gtk::AspectFrame
- Gtk::Paned
- Gtk::ScrolledWindow
- Gtk::Expander
- Gtk::Popover
```

### Multiple-item Containers
Multiple-item Containers มีเมธอดอื่นนอกเหนือจาก set_child() และ unset_child() คอนเทนเนอร์ที่แตกต่างกันสามารถมีวิธีการที่แตกต่างกันในการเพิ่มและลบวิดเจ็ตย่อย ตัวอย่างเช่น Gtk::Box มี append() และ remove() รวมถึงเมธอดอื่นๆ
container มีอยู่ 2 แบบ
- single-child containers
- multiple-child containers
วิดเจ็ตคอนเทนเนอร์ส่วนใหญ่ใน gtkmm เป็น single-child containers
```
multiple-child containers
- Gtk::Box
- Gtk::Grid
- Gtk::Notebook
- Gtk::ActionBar
- 
```