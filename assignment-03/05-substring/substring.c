#include <stdio.h>

int findLen(const char *str) {
    int len = 0;

    while(*str != '\0') {
        len++;
        str++;
    }

    return len;
}
int find_substring(const char *haystack, const char *needle) {

    int strLen = findLen(haystack);
    int subStrLen = findLen(needle);

    if(subStrLen > strLen) {
        return -1;
    }

    const char *iterator = haystack;
    int idx = 0;

    while(*iterator != '\0') {

        if(*iterator == *needle) {

            int charsFound = 0;
            const char *temp = iterator;
            const char *subIterator = needle;

            while(*temp != '\0' && *subIterator != '\0') {

                if(*temp == *subIterator) {
                    charsFound++;
                    temp++;
                    subIterator++;
                }
                else {
                    break;
                }
            }

            if(charsFound == subStrLen) {
                return idx;
            } 

            
        }

        iterator++;
        idx++;
    }

    return -1;
}
int main() {

    char str1[] = "Embedded Systems";
    char str2[] = "bed";

    printf("%d\n", find_substring(str1, str2));
}