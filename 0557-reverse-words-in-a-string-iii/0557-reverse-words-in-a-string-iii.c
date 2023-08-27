#include <stdio.h>
#include <string.h>

void reverseWord(char *start, char *end) {

    for(; start < end; start++, end--)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
    }
}

char * reverseWords(char * s){
    int length = strlen(s);
    
    char *start = s;
    char *end = s;
    
    for(; *end != '\0'; end++)
    {
        if (*end == ' ') {
            reverseWord(start, end - 1);
            start = end + 1;
        }
    }
    
    reverseWord(start, end - 1);
    
    return s;
}