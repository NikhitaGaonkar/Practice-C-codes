#include<stdlib.h>
#include<stdlib.h>

/*
Square without  * or carrot sigh
1*1 =1
2*2 = 4 =1+3
3*3 = 9 = 1+3+5;
4*4 = 16 = 1+3+5+7
....
so sum of odd nos
*/
int square(int a)
{
	int i=0, j =1;
	int sum =0;
	for(i=0; i<a; i++)
	{
		sum += j;
		j+=2;
	}
	return sum;
}


int main()
{
	printf("%d \n", square(6));
	printf("%d \n", square(30));
	return 0;
}
