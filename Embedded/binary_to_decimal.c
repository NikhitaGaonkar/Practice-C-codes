/*
 * C program to convert the given binary number into decimal
 eg, 7 = 00111  ie. 0*2^4 + 0*2^3 + 1*2^2 + 1*2^1 +1*2^0;
 */
#include <stdio.h>
#include <limits.h>
void main()
{
    int  num, binary_val, decimal_val = 0, rem = 0, base =1;
 
    printf("Enter a binary number(1s and 0s) \n");
    scanf("%d", &num); /* maximum five digits */
    binary_val = num;
    while (num > 0)
    {
        rem = num % 10;
        decimal_val += rem * base;
        num /= 10 ;
        base *= 2;
    }
    printf("The Binary number is = %d \n", binary_val);
    printf("Its decimal equivalent is = %d \n", decimal_val);
    printf("%d", INT_MAX);
}

