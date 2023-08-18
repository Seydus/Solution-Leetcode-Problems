void swap(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void moveZeroes(int* arr, int n)
{
    int count = 0;
  
	    for(int i =0; i<n;i++)
	    {
	        if(arr[i] != 0)
	        {
	            swap(&arr[i], &arr[count++]);
	        }
	    }
}
