#include<stdio.h>
#include<stdlib.h>

/*   SELECTION SORT
  
  In iteration i, find index min of the smallest remaining entry
  swap a[i] and a[min]  

  e.g.
		  i       min 
  a[8] = {8,5,2,6,1,4,3,7}
            i min        //swapped 8 and 1 and so on.. 
  a[8] = {1,5,2,6,8,4,3,7}
              i       min
  a[8] = {1,2,5,6,8,4,3,7}
                i  min
  a[8] = {1,2,3,6,8,4,5,7} 
                i &min
  a[8] = {1,2,3,4,8,6,5,7}  
                  i  min
  a[8] = {1,2,3,4,8,6,5,7}  
                    i&min
  a[8] = {1,2,3,4,5,6,8,7}  
                      i min
  a[8] = {1,2,3,4,5,6,8,7} 
                        i&min
  a[8] = {1,2,3,4,5,6,7,8} 
                     
  a[8] = {1,2,3,4,5,6,7,8}  
  
  O(N^2)
  N swaps
  */
int compLT_func(int *a,  int *b)
{
	if(*a < *b)
      return 1;
	
	return 0;
}

void swap(const void *a, const void *b)
{
	int temp = *(int *)a;
	*(int *)a = *(int *)b;
	*(int *)b = temp;
}

void selection_sort(int *arr, int size)
{
  	int i, j;
	for(i=0; i<size; i++)
	{
		int min = i;
		//find minimum element in the remaining elements
		for(j=i+1; j<size; j++)
		  if(compLT_func(&arr[j], &arr[min]))
			  min = j;
		swap(&arr[i], &arr[min]);
	}
}

int main(void)
{
	int arr[] ={8,5,2,6,1,4,3,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	selection_sort(arr, size);
	int i =0;
	for(i=0; i<size; i++)
	  printf("%d", arr[i]);
	return 0;
}
