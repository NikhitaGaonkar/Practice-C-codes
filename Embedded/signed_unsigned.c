#include<stdlib.h>
#include<stdio.h>

//signed and unsigned addition
/*Because 4294967282>6 is true you will get >6 as output. 
4294967282 is coming from assigning -14 to a unsigned int. (a+b) will be converted as 2^32 - 14. 


I think the OP is not confused about the ternary operator its a different problem.

From the C99 standard, section 6.3.1.8 ("Usual arithmetic conversions"):

if the operand that has unsigned integer type has rank greater or equal to the rank of the type of the other operand, 
then the operand with signed integer type is converted to the type of the operand with unsigned integer type.
unsigned int and int has the same rank, so it's equivalent to:

(a + (unsigned int)b > 6)
To fix it, you need to explicitly cast in the other direction, i.e.:

((int)a + b > 6)

*/

int myArray[3][4] =
{
    {0, 3, 6, 9},
    {1, 4, 7, 10},
    {2, 5, 8, 11}
};
void arrayMath()
{
    ///int (*ptr)[4] = &myArray;
    int r = 2;
    int c = 2;
    int *val = (*(myArray + r)+c);
    printf("%d \n", *(*(myArray + r)+c));
    
    // code here
}

int main()
{
  unsigned int a=6;
  int b=-20;

  (a+b)>6?puts(">6"):puts("<=6");
  ((int)a+b)>6?puts(">6"):puts("<=6");
  
  printf("///////////\n");
  printf("+ = %d\n",a+b );
  printf("- = %d\n",a-b );
  printf("* = %d\n",a*b );
  printf("/ = %d\n",b/a );
  
  arrayMath();
  printf("\n");
  printf("%d\n", -INT_MAX );
  printf("%d\n", INT_MIN);
}
