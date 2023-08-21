#include <stdio.h>
#include <stdlib.h>

#define SIZE 101

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* hashmap = (int*)calloc(SIZE, sizeof(int));
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) 
    {
        hashmap[nums[i]]++;
    }
    
    for (int i = 0; i < numsSize; i++) 
    {
        int count = 0;
        
        for (int j = 0; j < nums[i]; j++) 
        {
            count += hashmap[j];
        }

        result[i] = count;
    }
    
    *returnSize = numsSize;
    free(hashmap);
    return result;
}