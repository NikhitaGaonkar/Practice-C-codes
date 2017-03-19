#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*
  log(64) = log(2 ^ 6) = 6log(2)
  log(64)/log(2) = 6;
  64 binary : 000....0001000000
  reverse of 64: 0000001000....000 ie 2^25 (31-6)
*/
int rever_bit_pow_two(int pow_two)
{
	int pos = log(pow_two)/log(2);
	printf("pos %d\n", pos);
	return pow(2, 31-pos);
}

//wrong way ...looks correct but reverse output
void print_binary(int num)
{
	int bit = 0;
	while(num)
	{
		if(num&1)
		  printf("1");
		else
		  printf("0");
		num = num>>1;
	}
	printf("\n");
}

//correct way
/*
  check if ith bit is ON or OFF by bitwise ANDing it with 2^i;
  e.g
  0th bit : bit = 2^0,  if NUM & bit == 1 then ON else OFF
  5th bit : bit = 2^5 , if NUM & bit == 1 then ON else OFF
  
  1<< 32 is 2 ^31;
  so the foll logic checks all bits form 31 to 0 in 32 bit integer
*/
#if 1 
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
    printf("\n");
}
#endif
 
#if 0 //recursive
void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n/2);
 
    /* step 2 */
    printf("%d", n % 2);
}
#endif
 
int main()
{
	int num = 64;
	bin(num);
	int rev_num =  rever_bit_pow_two(num);
	bin(rev_num);
	return 0;
}
