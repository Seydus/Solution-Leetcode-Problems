#include <stdio.h>
#include <stdbool.h>

int numJewelsInStones(char * jewels, char * stones) {
    bool isJewel[128] = {false}; 

    for (int i = 0; jewels[i] != '\0'; i++) {
        isJewel[jewels[i]] = true;
    }

    int n = 0;

    for (int i = 0; stones[i] != '\0'; i++) {
        if (isJewel[stones[i]]) {
            n++;
        }
    }

    return n;
}