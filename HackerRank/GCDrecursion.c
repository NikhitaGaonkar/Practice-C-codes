#include<stdio.h>
#include<math.h>

/*
the math:
GCD(x,y)
if x==y, gcd is x or y
else gcd= GCD(x-y, y)
*/
void GCD(int X, int Y)
{
	if(X==Y)
	{
	  printf("%d \n", Y );
	  return;
	}
	int greater, smaller;
	greater = X>Y ? X:Y;
	smaller = Y<X ? Y:X;
	int rem;
	rem = greater%smaller;
	if(rem !=0)
      GCD(smaller, rem);
    else
      printf("%d \n", Y );
}

int main()
{
  GCD(1701,3768);
  GCD(10, 45);
  GCD(18,9);
  GCD(99,99);
  	
	return 0;
}
