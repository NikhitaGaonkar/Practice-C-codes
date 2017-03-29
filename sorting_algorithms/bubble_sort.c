#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
	optimized bubble sort, no swaps if array is already sorted
	Best case: sorted array, check once O(n)
	Worst case: reversed array, O(n2)
	Average case: O(n2)
	Space: in-place O(1)
*/
#define CompGT(a, b) (a>b)

void bubble_sort(int *arr, int size)
{
	if(arr == NULL || size <=1) return;
	int swap = 0;
	int temp = 0;
	int iter =0;
	do{
		swap = 0; //reset swap
		for(iter=0; iter<size; ++iter)
		{
			if(CompGT(arr[iter], arr[iter+1]))
			{
				temp = arr[iter];
				arr[iter] = arr[iter+1];
				arr[iter+1] = temp;
				swap = 1;
				
			}
		}
		printf("%d", swap); //testing how many swaps
		
	}while(swap == 1);
	printf("\n");
}

void print(int *arr, int size)
{
	int i;
	for(i=0; i<size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = {10, 20, 15, 10, 90, 67, 2, 8};
	int size = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr, size);
	print(arr, size);
	
	int arr1[] = {1,2,3,4,5};
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	bubble_sort(arr1, size1);
	print(arr1, size1);
	
	int arr2[] = {1,1,1,1,1,1};
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	bubble_sort(arr2, size2);
	print(arr2, size2);
	
	int arr3[] = {-1, -1, -1,0};
	int size3 = sizeof(arr3)/sizeof(arr3[0]);
	bubble_sort(arr3, size3);
	print(arr3, size3);
	
	int arr4[] = {INT_MAX, INT_MIN};
	int size4 = sizeof(arr4)/sizeof(arr4[0]);
	bubble_sort(arr4, size4);
	print(arr4, size4);
	
	int arr5[] = {10, 9, 8, 7, 6};
	int size5 = sizeof(arr5)/sizeof(arr5[0]);
	bubble_sort(arr5, size5);
	print(arr5, size5);	
	
	return 0;
}
