#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2)
{
    int size = strlen(word1) + strlen(word2);
    char* result = (char*)malloc((size + 1) * sizeof(char));
    int i = 0, x = 0, y = 0;

    for (i = 0; i < size; i++) 
    {
        if ((i % 2 == 0 && x < strlen(word1)) || 
            (i % 2 != 0 && y == strlen(word2)))
        {
            result[i] = word1[x];
            x++;
        }
        else
        {
            result[i] = word2[y];
            y++;
        }
    }

    result[size] = '\0';
    return result;
}