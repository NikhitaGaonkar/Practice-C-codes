// A C++ program to find floor(sqrt(x)
#include<stdlib.h>
#include<stdio.h>

// Returns floor of square root of x
int sqrt(int x)
{
	// Base cases
	if (x == 0 || x == 1)
	return x;

	// Staring from 1, try all numbers until
	// i*i is greater than or equal to x.
	int i = 1, result = 1;
	while (result <= x)
	{
	if(result == x)
      return i;
	i++;
	result = i*i;
	}
	return i-1;
}

int sqrt_better(int x)
{
	int start =1, end=x;
    int mid =0, res =0;
	while(start<end)
	{
		mid = (start+end)/2;
		if(mid*mid == x)
		  return mid;
		  
	    //if mid is greater than x means the root lies to left of mid eg 5*5 >9
	    if(mid*mid > x)
	      end = mid-1;
		else //root lies on right of mid so adjust start
		{
			start = mid+1;
			res = mid; //since less and if not perfect square
		}
	}
	
	return res;
}
// Driver program
int main()
{
	int x = 17;
	printf("%d\n", sqrt(x));
	printf("%d\n", sqrt_better(x));
	return 0;
}

