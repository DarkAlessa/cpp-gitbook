#### ANSI escape codes
```
     Forground "\033[38;2;<R>;<G>;<B>m"
     Backgroud "\033[48;2;<R>;<G>;<B>m"

    Set 
     "\033[1m"  Bold/Bright
     "\033[2m"  Dim
     "\033[3m"  Italic
     "\033[4m"  Underlined
     "\033[5m"  Blink
     "\033[7m"  Reverse (invert the foreground and background colors)
     "\033[8m"  Hidden (useful for passwords) 

    Reset
     "\033[0m"  Reset all attributes
     "\033[21m" Reset bold/bright
     "\033[22m" Reset dim
     "\033[23m" Reset italic
     "\033[24m" Reset underlined
     "\033[25m" Reset blink
     "\033[27m" Reset reverse
     "\033[28m" Reset hidden
```
---
```c++
#include <iostream>

int main() {
   
    std::cout << "\033[1m" << "\033[38;2;255;102;255m" << " Bold Text " << "\033[0m" << '\n';
    std::cout << "\033[4m" << "\033[38;2;51;255;51m" << " Underline Text " << "\033[0m" << '\n';
    std::cout << "\033[38;2;0;0;0m" << "\033[48;2;102;178;255m" << " TEXT COLOR " << "\033[0m" << '\n';
    std::cout << "\033[1m" << "\033[38;2;0;0;0m" << "\033[48;2;102;178;255m" << " TEXT " << "\033[0m" 
              << "\033[38;2;0;0;0m" << "\033[48;2;255;153;51m" << " COLOR " << "\033[0m" << '\n';
}
```
---
```c++
int main() {
    std::cout << "\033[3m" << '\n';   // set italic
    std::cout << "hello" << '\n';     // italic
    std::cout << "hello" << '\n';     // italic
    std::cout << "\033[23m" << '\n';  // reset italic
    std::cout << "world" << '\n';     // normal text
}
```
---
```c++
#include <iostream>
#include <string>
#include <cstdint>

// SET << FG << BG << TEXT << RESET
class Text {
public:
    explicit Text(std::string&& ss) : text{"", "", "", ss, "\033[0m"} {}

    Text& style(uint8_t s) { 
        text[0] = "\033[" + std::to_string(s) + "m";
        return *this;
    }

    Text& operator=(std::string&& ss) {
        text[3] = ss;
        return *this;
    }

    Text& fgcolor(uint8_t r, uint8_t g, uint8_t b) {
        text[1] = "\033[38;2;" + 
                std::to_string(r) + ";" +
                std::to_string(g) + ";" +
                std::to_string(b) + "m";
        return *this;
    }

    Text& bgcolor(uint8_t r, uint8_t g, uint8_t b) {
        text[2] = "\033[48;2;" + 
                std::to_string(r) + ";" +
                std::to_string(g) + ";" +
                std::to_string(b) + "m";
        return *this;
    }

    void printText() { 
        for (auto& t : text) { std::cout << t ; }
        //std::cout << '\n';
    }

private:
    std::string text[5] = {""};
};

int main() {
    Text text1(" Hello World ");
    text1.style(1).fgcolor(0, 0, 0).bgcolor(255, 102, 102);
    text1.printText();

    Text text2(" Lisa Blackpink ");
    text2.style(1).fgcolor(0, 0, 0).bgcolor(178, 255, 102);
    text2.printText();

    Text text3(" I Love You ");
    text3.style(1).bgcolor(10, 140, 120);
    text3.printText();

    text1 = " 555 ";
    text1.printText();

}
```
---
```c++
#include <iostream>

#define FG(R,G,B)  "\033[38;2;" #R ";" #G ";" #B "m"   // foreground color
#define BG(R,G,B)  "\033[48;2;" #R ";" #G ";" #B "m"   // background color

// Set
#define BOLD      "\033[1m" // ตัวหนา
#define DIM       "\033[2m" // ปรับความทึบ
#define ITALIC    "\033[3m" // ตัวเอียง
#define UNDER     "\033[4m" // ขีดเส้นใต้
#define REVERSE   "\033[7m" // กลับสี foreground กับ background

// Reset
#define RESET     "\033[0m" // รีเซ็ตค่า

int main() {
    // Syntax : Set << FG << GB << "TEXT" << Reset
    std::cout << FG(255,255,0) << " No background color " << RESET << "\n";
    std::cout << BOLD    << FG(255,128,0)   << BG(64,64,64)  << " BOLD          " << RESET << "\n";
    std::cout << DIM     << FG(255,128,0)   << BG(64,64,64)  << " DIM           " << RESET << "\n";
    std::cout << UNDER   << FG(114,227,237) << BG(0,51,102)  << " UNDERLINED    " << RESET << "\n";
    std::cout << ITALIC  << FG(255,255,255) << BG(51,153,35) << " ITALIC        " << RESET << "\n"; 
    std::cout << ITALIC  << UNDER << FG(32,32,32) << BG(255,204,153) << " ITALIC + UNDER " << RESET << "\n";

    std::cout << BOLD    << FG(255,128,0) << BG(64,64,64) << " NORMAL "  << RESET 
              << REVERSE << FG(255,128,0) << BG(64,64,64) << " REVERSE " << RESET
              << "\n"; 

    std::cout << BOLD << FG(0,0,0) << BG(224,187,228) << " Alice "      << RESET
              << BOLD << FG(0,0,0) << BG(216,242,233) << " In "         << RESET
              << BOLD << FG(0,0,0) << BG(119,179,181) << " Wonderland " << RESET
              << "\n";
}
```