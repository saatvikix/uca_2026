#include <stdio.h>

int my_strlen(const char *str) {
    int len = 0;

    while(*str != '\0') {
        len++;
        str++;
    }

    return len;
}
int main() {

    const char *name = "Saatvik";
    printf("Length calculated: %d\n", my_strlen(name));

    return 0;
}