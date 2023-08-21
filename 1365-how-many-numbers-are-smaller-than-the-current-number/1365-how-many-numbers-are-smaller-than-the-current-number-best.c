#include <stdio.h>
#include <stdlib.h>

#define SIZE 101

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int freq[SIZE] = {0};
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) 
    {
        freq[nums[i]]++;
    }

    for (int i = 1; i < SIZE; i++) 
    {
        freq[i] += freq[i - 1];
    }
    
    for (int i = 0; i < numsSize; i++) 
    {
        result[i] = nums[i] == 0 ? 0 : freq[nums[i] - 1];
    }
    
    *returnSize = numsSize;
    return result;
}
