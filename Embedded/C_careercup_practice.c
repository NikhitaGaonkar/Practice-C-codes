#include<stdio.h>

/*
Modify the program by adding another integer pointer variable r which is also an alias for variable i. 
 Add print statements to output the dereferenced values of q and r.
*/
int main()
{
   int i = 200, *p, *q;
   int *r = i;
   p = &i;
   q = p;
   *q = *q + 1;
   printf("*p = %d\n", *p);
   printf("*q = %d\n", *q);
   printf("Dereferanced value of r = %d\n", r);

	int x = sum(4,7);
	printf("Sum = %d \n", x);
   return 0;


}

int sum( int x, int max ) 
{ 
  if(x>max)
   return 0;
   
  return (x + sum(x+1,max));
} 
