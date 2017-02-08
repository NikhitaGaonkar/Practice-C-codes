#include<stdlib.h>
#include<stdio.h>
//leetcode
/*
Given a non negative integer number num. For every numbers i in the range 0 = i = num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/
#define IS_POW_OF_2(X) (!(X & (X-1)))

int *counting_bits(int n)
{
  int *bits = (int *)malloc(sizeof(int)*n);
  bits[0] = 0;
  bits[1] = 1;
  int pow_of_2 = 2;
  int i;
  
  for(i=2; i<n; i++)
  {
  	if(IS_POW_OF_2(i))
  	{
  	  bits[i] =1;
  	  pow_of_2 = i;
  	}
  	else
  	  bits[i] = bits[pow_of_2] + bits[i-pow_of_2];
  }
  for(i=0; i<n; i++)
    printf("%d", bits[i]);
    
  printf("\n");
  int *ptr = &bits[0];
  return (ptr);
}

int main()
{
	int i=0, n= 5;
	int *ptr = counting_bits(n);
	for(i=0; i<n; i++)
	  printf("%d", *ptr);
	return 0;
}
