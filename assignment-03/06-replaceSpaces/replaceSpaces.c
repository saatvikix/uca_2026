#include <stdio.h>

void url_encode(char *str, int true_length) {
    
    int spaces = 0;

    for(int i=0; i<true_length; i++) {
        if(str[i] == ' ') {
            spaces++;
        }
    }

    int newSize = true_length + spaces *2;

    char result[newSize+1];

    int i = 0;
    int j = 0;

    while(j<true_length) {

        if(str[j] == ' ') {
            
            result[i++] = '%';
            result[i++] = '2';
            result[i] = '0';
        }

        else {
            result[i] = str[j];
        }

        i++;
        j++;
    }

    result[newSize] = '\0';

    for(int i=0; i<=newSize; i++) {
        str[i] = result[i];
    }
    
}
int main() {
    
    char str[100] = "Hello World";   
    url_encode(str, 18);
    printf("%s\n", str);

    return 0;
}