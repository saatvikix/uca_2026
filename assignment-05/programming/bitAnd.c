#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {

    int x = 4;  // 1 0 0 
    int y = 7;  // 1 1 1
    
    printf("%d\n", bitAnd(x, y));   

    return 0;
}