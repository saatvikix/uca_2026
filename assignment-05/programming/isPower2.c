#include <stdio.h>

int isPower2(int x) {
    return !!x & !(x & (x + ~0)) & !((x >> 31) & 1);
}

int main() {

    printf("%d\n", isPower2(2));
    printf("%d\n", isPower2(1));
    printf("%d\n", isPower2(0));
    printf("%d\n", isPower2(12));
    printf("%d\n", isPower2(25));
    printf("%d\n", isPower2(64));
}