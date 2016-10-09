#include<stdlib.h>
#include<stdio.h>

/*
in a factorial the zeroes are contributed by 5 and 2
the idea is to find teh prime factors of a number
and counting the no of 5 in it gives the no of triling 0s

n = 5: There is one 5 and 3 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So count of trailing 0s is 1.
n = 11: There are two 5s and three 2s in prime factors of 11! (2 8 * 34 * 52 * 7). So count of trailing 0s is 2.
We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. 
So if we count 5s in prime factors, we are done. How to count total number of 5s in prime factors of n!? A simple 
way is to calculate floor(n/5). For example, 7! has one 5, 10! has two 5s. It is done yet, there is one more thing to consider. 
Numbers like 25, 125, etc have more than one 5. For example if we consider 28!, we get one extra 5 
and number of 0s become 6. Handling this is simple, first divide n by 5 and remove all single 5s, 
then divide by 25 to remove extra 5s and so on. Following is the summarized formula for counting trailing 0s.

Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
*/
int trailing_zeroes_factorial(int num)
{
	int i,count =0;
	for(i=5; num/1>0; i*5)
	  count = num/i;  //to find the no of multiples of m in n, just divide n by m
	  
	return count;
}

int main()
{
	int n = 20;
	printf("%d ", trailing_zeroes_factorial(n));
	return 0;
}
