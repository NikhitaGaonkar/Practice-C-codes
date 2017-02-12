#include<stdio.h>
#include<stdlib.h>

/*
   INSERTION SORT
   
   like a deck of cards
          i  
   a[] = {5,3,1,7}
          j i
   a[] = {5,3,1,7}
   temp = 3
   a[] = {5,5,1,7}
   insert temp
   a[] = {3,5,1,7}
   and so on...
   
   O(N^2), there are N elements, you compare through N-1 elements with upto N-1 shits
   stable sort as the order of elements is maintained
   
   if you do in-place without any temp  follow method 2
      
*/
int compGT(int *a, int *b)
{
	if(*a > *b)
	  return 1;
	
	return 0;
}
int compLT(int *a,  int *b)
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

void insertion_sort(int *arr, int lb, int ub)
{
	int i = lb;
	int j =0;
	for(i= lb; i<=ub; i++)
	{
		int temp = arr[i];
		//shift elements to right until insertion point found
		for(j= i-1; j>=lb; j--)
			if(compGT(&arr[j], &temp))
				arr[j+1] = arr[j];
			else break;

	    //insert the element
	    arr[j+1] = temp;
	}
}

void insertion_sort2(int *arr, int size)
{
	int i,j;
	for(i=0; i<size; i++)
	{	//shift elements to right until insertion point found
		for(j= i; j>0; j--)
			if(compLT(&arr[j], &arr[j-1]))
				swap(&arr[j], &arr[j-1]);
			else break;
	}
}


int main(void)
{
	int arr[] ={8,5,2,6,1,4,3,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr, 2,5);
	int i =0;
	for(i=0; i<size; i++)
	  printf("%d", arr[i]);
	  
	printf("\n");  
	
	insertion_sort2(arr, size);
    for(i=0; i<size; i++)
	  printf("%d", arr[i]);

	return 0;
}
