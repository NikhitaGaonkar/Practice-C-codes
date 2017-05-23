#include<stdlib.h>
#include<stdio.h>
#include<math.h>
/*
	power set
	Set  = [a,b,c]
	power_set_size = pow(2, 3) = 8
	Run for binary counter = 000 to 111

	Value of Counter        Subset
		000           -> 	Empty set
		001           -> 	a
		011           -> 	ab
		100           -> 	c
		101           -> 	ac
		110           -> 	bc
		111           -> 	abc

*/


void print_power_set(int *set, int set_size)
{
	
	int max_subsets = pow(2, set_size);
	int count=0, i=0;
	
	for(count = 0; count < max_subsets; ++count)
	{
		for(i=0; i<set_size; ++i)
		{
			if(count & 1<<i)
			   //if i th bit of count is set, 
			   //then print i th element of set
			  printf("%d ", set[i]);
		}
		printf("\n");
	}
}

int main(void)
{
	int set[] = {1,2,2,4};
	int set_size = sizeof(set)/sizeof(set[0]);
	print_power_set(set,set_size);
	return 0;
}
