#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "C, C++, Java, Python, Rust";
    char *tokens = strtok(str, ", ");

    while(tokens != NULL) {
        printf("%s", tokens);
        printf("\n");

        tokens = strtok(NULL, ", ");
    }

    return 0;
}