#include<stdio.h>
#include<stdlib.h>

int myArray[3][4] =
{
    {0, 3, 6, 9},
    {1, 4, 7, 10},
    {2, 5, 8, 11}
};
void arrayMath()
{
    int (*ptr)[3][4] = &myArray;
    int row = 0;
    int col = 0;
    int val = *(int*)(ptr+1*row+1*col);
    printf("%d \n", val);
    
    // code here
}

int main()
{
	arrayMath();
}
