// C Program to shuffle a given array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A utility function to swap to integers
void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// A utility function to print an array
void printArray (int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int random(int lower, int higher)
{
    return ((int)(rand()%(higher+1)));
}
// A function to generate a random permutation of arr[]
void randomize ( int arr[], int n )
{
	// Use a different seed value so that we don't get same
	// result each time we run this program
	srand ( time(NULL) );
    int i;
	// Start from the last element and swap one by one. We don't
	// need to run for the first element that's why i > 0
	for (i = n-1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		int j = rand() % (i+1);

		// Swap arr[i] with the element at random index
		swap(&arr[i], &arr[j]);
	}
}
void randomizeM ( int arr[], int n, int m )
{
	// Use a different seed value so that we don't get same
	// result each time we run this program
	srand ( time(NULL) );
    int i, k = 0;
	// Start from the last element and swap one by one. We don't
	// need to run for the first element that's why i > 0
	for (i = m-1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		//int j = rand() % (i+1);
		int j= random(0, n-1-k);
        k++;
		// Swap arr[i] with the element at random index
		swap(&arr[i], &arr[j]);
	}
}

// Driver program to test above function.
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr)/ sizeof(arr[0]);
	randomize (arr, n);
	printArray(arr, n);
	//for m elements
	int m=4;
	randomizeM (arr, n, m);
	printArray(arr, m);

	return 0;
}

