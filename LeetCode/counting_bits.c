#include<stdlib.h>
#include<stdio.h>
//leetcode
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
