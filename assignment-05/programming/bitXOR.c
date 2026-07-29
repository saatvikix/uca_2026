#include <stdio.h>

int bitXOR(int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));
}

int main() {

    int x = 4;  // 1 0 0 
    int y = 7;  // 1 1 1
    
    printf("%d\n", bitXOR(x, y));  // 0 1 1  ===> i.e.(3) 

    return 0;
}