#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char ch = 'a';
	char *p1 = &ch;
	char **p2 = &p1;
	
	printf("p1 = %d \n", p1);
	printf("*p1 = %c \n", *p1);
	printf("p2 = %d \n", p2);
	printf("*p2 = %d \n", *p2);
	printf("**p2 = %c \n", **p2);
	
	return 0;
}

/* OUTPUT 
 p1 = 2293319   address of p1
 *p1 = a        value at p1
 p2 = 2293304   address of p2
 *p2 = 2293319  address of p1
 **p2 = a       value at p1 

*/
