/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int factorial(int n)
{
    if(n <= 0) return 0;
    if(n==1) return 1;
    int fact =1;
    
    for(int i=1; i<=n; ++i)
    {
        fact *= i;
    }
     return fact;
    
}

void swap(int *x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute_util(int *array, int *nums, int left, int right, int array_index)
{
    if(left == right)
    {
        int col = sizeof(nums)/sizeof(nums[0]);
        for(int j=0; j< col; ++j)
          *(*(array+array_index)+j)= nums[j];
        array_index++;
    }
    
    for(int i=left; i<right; ++i)
    {
        swap(nums[left], nums[i]);
        permute_util(array,nums, left+1, right, array_index);
        swap(nums[left], nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize) { 
    
    //int num_size = sizeof(nums)/sizeof(nums[0]);
    int returnSize = factorial(numsSize);
    
    int **arr = (int **)malloc(sizeof(int) * returnSize);
    for(int i =0; i< returnSize; ++i)
      arr[i] = (int *)malloc(sizeof(int) * numsSize);
      
    permute_util((int *)array, nums, 0, numsSize, 0);
    
    return arr;
  
}