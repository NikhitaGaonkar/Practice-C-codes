#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256


//both work!!!!
//int AreAnagrams(const char *str1, const char *str2)
int AreAnagrams(char *str1, char *str2)
{
	int count1[MAX]={0};
	int count2[MAX]= {0};
	int i=0;
	
	for (i=0; (str1[i] && str2[i]); i++)
    {
    	count1[str1[i]]++;
    	count2[str2[i]]++;
	}

    if(str1[i] || str2[i])
       return 0;
       
    for(i=0; i<MAX; i++)
    {
    	if(count1[i] != count2[i])
    	return 0;
	}
   
   return 1;
}


static int myCompare (const void * a, const void * b)
{
//	printf("in mycompasre %d", AreAnagrams(*(const char **)a,*(const char **)b));
//	return (AreAnagrams(*(const char **)a,*(const char **)b));
 	return (AreAnagrams(*(char **)a,*(char **)b));
    
}

void sort(const char *arr[], int n)
{
	qsort (arr, n, sizeof (const char *), myCompare);
}

int main ()
{
	const char *arr[] = {"acca", "ddeea", "ccaa", "eeadd"};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;

	printf("Given array is\n");
	for (i = 0; i < n; i++)
		printf("%d: %s \n", i, arr[i]);

    printf("testing %d", AreAnagrams(arr[0], arr[2]));
	sort(arr, n);

	printf("\nSorted array is\n");
	for (i = 0; i < n; i++)
		printf("%d: %s \n", i, arr[i]);

	return 0;
}

