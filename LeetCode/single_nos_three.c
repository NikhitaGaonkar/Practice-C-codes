#include<stdlib.h>
#include<stdio.h>
//leetcode

/*
Explanation: 
qs: you have given n numbers, all numbers are repeating except 2.
ex: 1,2,4,5,7,3,1,2,3,4 [5,7 non-repeating].
Solution: XOR of entire array : for same number XOR will be zero so you will get XOR of 5 and 7.
Now a xor b !=0 if a!=b. so xor will be non zero hence there will be at least one set bit , in this ex 5 xor 7 = 101 xor 111 =010
find this set bit. Now you found this set bit in xor of two numbers so this bit will present in either in a or b (like in above ex its in 7).
Now take two xor one for the numbers that have set bit and other that don't have this set bit.
In our example:
xor1=xor of {2,7,3,2,3} xor2= xor of {1,4,5,1,4} as we know all the elements are repeated except two and we now able to separate
these two numbers, and same repeated number will be in same side because of same bit representation for ex {1,1} will always in same partition.
Now xor1 will be =7 because xor of same number will be zero. and by same logic xor2=5.
*/

void single_number_three(int a[], int size, int *elem1, int *elem2)
{
	int xor = a[0];
	int i;
	//get xor of all nos
	//final xor contains only non-repeating chars
	// a^a =0 and a^b !=0
	for(i=1; i<size; i++)
	  xor ^= a[i];

	//find the bit where the two nos differ
	//find right ,most set bit of the xor
	int set_bit = xor & (~(xor-1));

    //printf("%d \n", xor);
	//to avoid garbage
	*elem1 = 0;
	*elem2 = 0;
	for(i=0; i<size; i++)
	{
	  if(a[i] & set_bit)
	    *elem1 = *elem1 ^ a[i];
	  else
	    *elem2 = *elem2 ^ a[i];
	}
	
}

int main()
{
	int arr[] ={1, 2, 1, 3, 2, 5};
	int a=0; int b=0;
	single_number_three(arr, 6, &a, &b);
	printf("a is %d \nb is %d \n", a,b);
	return 0;
}
