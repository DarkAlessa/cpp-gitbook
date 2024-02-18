ชื่อ Makefile หรือ makefile (GNU แนะนำ Makefile)
Makefile ประกอบด้วย Rule ดังนี้
                                                                                                                     
	target ... : prerequisites ...                                                          
		recipe                                                                          
		...                                                                                
		...                                                                               	                                                                                 
target มักจะเป็นชื่อของไฟล์ที่สร้างขึ้นโดยโปรแกรม
prerequisites คือไฟล์ที่ใช้เป็นอินพุตเพื่อสร้าง target, target มักขึ้นอยู่กับหลายไฟล์
recipe คือคำสั่งที่ใช้ดำเนินการ อาจมีหลายคือสั่ง

โคยค่าเริ่มต้น make ประมวลผลที่ target แรก (ไม่ใช่ target ที่เริ่มต้นด้วยชื่อ ".") เรียกว่า default goal 

one :
	@echo "first target"
two :
	@echo "second target"

เมื้อใช้คำสั่ง make ผลลัพธ์คือพิมพ์ first target
ถ้าใช้คำสั่ง make two ผลลัพธ์คือพิมพ์ second target