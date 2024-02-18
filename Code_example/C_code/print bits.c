#include <stdio.h>
#include <stdint.h>

void pb(uint8_t* x) {
    for(int i = 0; i < 8; i++) {
        printf("%u", 0b10000000 & (*x << i) ? 1 : 0);
    }
}

int main(int argc, char** argv) {
    uint8_t n = 0b00110001;
    pb(&n);
    return 0;
}