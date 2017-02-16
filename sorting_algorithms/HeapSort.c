#include<stdio.h>
#include<stdlib.h>

typedef int T;

void swap(T *a, T *b)
{
	T t;
	t = *a;
	*a = *b;
	*b =t;
}


void maxHeapify(T *array, int n, int i)
{
  int largest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left<n && array[left] > array[largest])
    largest = left;
  if(right<n && array[right] > array[largest])
    largest = right;

  if(largest != i)
  {
    swap(&array[i], &array[largest]);
    maxHeapify(array, n, largest);
  }
}


void heapSort(T *array, int n)
{
  int i=0;
  for(i = n/2-1; i>=0; i--)
    maxHeapify(array, n, i);

  for(i= n-1; i>=0; i--)
  {
    swap(&array[0],&array[i]);
    maxHeapify(array, i, 0);
  }

}

int main()
{
    int arr[] = {12, 21, 1, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
    int i=0;
    printf("Sorted array is \n");
    for(i= 0; i<n; i++)
      printf("%d ", arr[i]);
}


