#include<stdio.h>
#include<stdlib.h>

/*
   MERGE SORT
   
   Divide the  array into two halves 
   Recursively sort the two halves
   Merge two halves
   
                 38 27 43 9 3
                       /  \
               38 27 43   9 3
			      /  \    /  \
			 38 27	 43  9    3
             /	\	  \	  \   /
		   38    27   43   3 9
		    \    /     \    |
 	 		 27 38    43   3 9
			    \      /    |
				27 38 43   3 9
				    \       /
				   3 9 27 38 43
				   
	Merge: Given two sorted subarrays a[lo] to a[mid] and a[mid+1] to a[hi]
	       replace with sorted subarray a[lo] to a[hi]

		   
    Best case: Sorted array O(N logN)
	Worst case: Reverse order O(N logN)
	Average case: O(N logN)
	Space: O(N)->array
	       O(N logN)->linked list
		   
    Practical Improvements
	1) Use insertion sort for small subarrays
       -> merge sort has too much overheads for small subarrays
       -> cutoff to insertion sort to 7 elements
    2) stop if already sorted
	   -> if biggest item in first half <= smallest item in second half
	   ->helps for partially sorted arrays
	   
	BOTTOMUP Merge sort
	sort the array in iterative way
	pass through the array, merging in size of 1
	repeat for subarrays of size 2, 4, 8, 16...
	
*/
#define IMPROVE_ONE 0
#define IMPROVE_TWO 1

int compLT(int *a, int *b)
{
	if(*a < *b)
      return 1;
  
    return 0;
}

void merge(int *arr, int lo, int mid, int hi)
{
	int i, j ,k;
	int aux_arr[hi];
	//copy into axillary array
	for(k=0; k<=hi; k++)
	  aux_arr[k] = arr[k];
	i = lo;
	j= mid+1;
	for(k=lo; k<=hi; k++)
	{
		if(i > mid) 
			arr[k] = aux_arr[j++]; //copy right array
		else if(j > hi)
			arr[k] = aux_arr[i++]; //copy left array
		//sorted merge
		else if(compLT(&aux_arr[i], &aux_arr[j])) 
			arr[k] = aux_arr[i++];
		else
			arr[k] = aux_arr[j++];
	}
	
}

void merge_sort(int *arr, int lo, int hi)
{
	if(hi <= lo) return;
#if IMPROVE_ONE
    if(hi <= lo + CUTOFF-1)
	{
		insertion_sort(a, lo, hi);
		return;
	}
#endif
   	int mid = lo+(hi-lo)/2;
	merge_sort(arr, lo, mid);
	merge_sort(arr, mid+1, hi);
#if IMPROVE_TWO
    if(compLT(&arr[mid],&arr[mid+1]))
		return;
#endif
	merge(arr, lo, mid, hi);
	
}

int getMin(int a, int b)
{
	if(a<b) return a;
	
	return b;
}
//iterative method
void bottomUp_merge_sort(int *arr, int size)
{
	int sz, lo;
	for(sz=1; sz<size; sz =sz+sz)
		for(lo=0; lo<size-sz; lo+= sz+sz)
			merge(arr, lo, lo+sz-1, getMin(lo+sz+sz-1, size-1));
	
}

int main(void)
{
	int arr[] ={8,5,2,6,1,4,3,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i =0;
	for(i=0; i<size; i++)
	  printf("%d", arr[i]);
	
	printf("\n");
	//bottomUp_merge_sort(arr, size);
	merge_sort(arr, 0,7);
	
	for(i=0; i<size; i++)
	  printf("%d", arr[i]);
	return 0;
}





