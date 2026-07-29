#include <stdio.h>
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {

    int signBit = x >> 31;
    return signBit | !!x;

}

int main() {

    printf("sign(130)   =  %d\n", sign(130));
    printf("sign(200)   =  %d\n", sign(200));
    printf("sign(-200)  = %d\n", sign(-200));
    printf("sign(-1000) = %d\n", sign(-1000));
    printf("sign(0)     =  %d\n", sign(0));
}