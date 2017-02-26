#include<stdlib.h>
#include<stdio.h>

//simple ceil in C

int my_ceil(float num)
{
	int inum = (int)num;
	if(num == (float)inum)
		return num;
	else
	{
		int sign = 1;
		
		if(num < 0)
		  sign = -1;
	    
		return (abs(num)+1) * sign;
	}
}

int main()
{
	float a = 3.210;
	printf("%d\n", my_ceil(a));
	
	a = 3.000;
	printf("%d\n", my_ceil(a));
	
	a = (float)1/2;
	printf("%f\n", a);
	printf("%d\n", my_ceil(a));
	
	a = -3.000;
	printf("%d\n", my_ceil(a));
	
	
	a = -3.235;
	printf("%d\n", my_ceil(a));
	
	
	return 0;
}
