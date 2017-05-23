// Program to print all permutations of a string in sorted order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Following function is needed for library function qsort(). */
int compare(const void *a, const void * b)
{
	return ( *(char *)a - *(char *)b );
}

// A utility function two swap two characters a and b
void swap_int(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// A utility function two swap two characters a and b
void swap_char(char* a, char* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void recursion(int *num, int i, int j) {
        if (i == j-1) 
		{
        	int l;
			for(l=0; l<j; ++l)
		  	  printf("%d ", num[l]);
			printf("\n");
			return;
        }
        
        int k;
        for ( k = i; k < j; k++) {
            if (i != k && num[i] == num[k])
              printf("dup \n");
            
          	swap_int(&num[i], &num[k]);
          	recursion(num, i+1, j);
        
        }
    }
    
    
 /*   1 AABC 
2 AACB 
3 ABAC 
4 ABCA 
5 ACAB 
6 ACBA 
7 BAAC 
8 BACA 
9 BCAA 
10 CAAB 
11 CABA 
12 CBAA 
    */
void permute_unique_int(int *arr, int left, int right)
{
    if(left == right-1)
	{		
		int i;
		for(i=0; i<right; ++i)
		  printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	
	int k =0;
	for(k= left; k<right; k++)
	{
		if((left!=k) && (arr[left]==arr[k])) 
		  continue;
		swap_int(&arr[left], &arr[k]);
		permute_unique_int(arr, left+1, right);
	}

}


void permute_unique_char(char *str, int left, int right)
{
	if(left == right-1)
	{
	    printf("%s\n", str);
	    return;
	}
	int k =0;
	for(k= left; k<right; ++k)
	{
		if(left!=k && str[left]==str[k]) 
		  continue;
		swap_char(&str[left], &str[k]);
		permute_unique_char(str, left+1, right);
	}
}

// Print all permutations of str in sorted order
void sortedPermutations(char str[])
{
	// Get size of string
	int size = strlen(str);

	// Sort the string in increasing order
	qsort(str, size, sizeof( str[0] ), compare);
	
	printf("%s\n", str);
	printf("\n");
printf("Hello\n");
	permute_unique_char(str, 0, size);
	
}

// Driver program to test above function
int main()
{
	char str[] = "ABCA";
   // sortedPermutations( str );
    
    int arr[] = {1,1,2};
    //qsort(arr, 3, sizeof( arr[0] ), compare);
    
    //permute_unique_int(arr, 0, 3);
    recursion(arr, 0, 3);
	return 0;
}

