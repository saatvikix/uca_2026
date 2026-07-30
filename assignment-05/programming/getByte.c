#include <stdio.h>

int getByte(int x, int n) {
    
    int mask = 0xFF;

    return ( x >> ( n << 3) ) & mask;

}

int main() {
    printf("0x%X\n", getByte(0x12345678, 1));
}