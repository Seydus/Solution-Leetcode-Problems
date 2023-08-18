void moveZeroes(int* nums, int numsSize)
{
    int i = 0, j = 0;
    
    for(i = 0; i < numsSize - 1; i++)
    {   
        if(nums[j] == 0 && nums[i + 1] != 0)
        {
            int temp = nums[j];
            nums[j] = nums[i + 1];
            nums[i + 1] = temp;
            j++;
        }
        
        if(nums[j] != 0)
        {
            j++;
        }
    }
}