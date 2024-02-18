//(1) Character Array 
    char c[] = "Hello";    // {'H', 'e', 'l', 'l', 'o', '\0'}
    std::cout << sizeof(c) << '\n';
    /*
       ขนาดของ c คือ 6 bytes เพราะ Hello + \0
    */

//(2) String Literal

    const char* ss = "Hello World";   // {'H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd', '\0'}
    std::cout << sizeof(ss) << '\n';
    // ขนาดของ ss คือ 8 bytes เพราะเป็น pointer
/* 
      Note: '\0' เรียกว่า null terminator หรือ null character
      null terminator จะต่อท้าย string literal เสมอ
*/

//(3) std::string จะไม่มี '\0' ต่อท้าย
    const std::string& ss = "Hello World";
    std::cout << sizeof(ss) << '\n';
    /*
       ขนาดของ ss คือ 32 bytes
       ถ้าใส่อักษร 5000 ตัวลงไปก็จะมีขนาด 32 bytes เหมือนเดิม 😍
    */

    /*
    std::string ไม่มี '\0' จึงไม่สามารถใช้ strlen() ของ C ได้ (C-style string)
    จะต้องแปลงโดยการใช้ c_str() โดย c_str() จะใส่ '\0' ต่อท้ายสตริง
   
      #include <cstring>
      ...
      std::cout << strlen(ss.c_str()) ;

    */ 

