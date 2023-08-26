#include <stdio.h>

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int i = 0;

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] < pivot) {
            ans[i++] = nums[j];
        }
    }

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] == pivot) {
            ans[i++] = nums[j];
        }
    }

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] > pivot) {
            ans[i++] = nums[j];
        }
    }

    *returnSize = numsSize;
    return ans;
}