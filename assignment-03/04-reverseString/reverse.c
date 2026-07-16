#include <stdio.h>

void reverse_string(char *str) {

    char *left = str;
    char *right = str;

    while(*right != '\0') {
        right++;
    }
    right--;

    while(left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}
int main() {

    char str[] = "Data Structures";

    printf("Before reversing: %s\n", str);
    reverse_string(str);
    printf("After reversing: %s\n", str);

    return 0;
}