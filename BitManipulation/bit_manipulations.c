#include<stdlib.h>
#include<stdio.h>
#include<math.h>


int set_bit_l_to_r(int x, int y, int l, int r)
{
	int sizeInt = sizeof(int)*8;
	if (l >= sizeInt || r >= sizeInt)
		return y;

	if (l > r)
	{
		int tmp = l;
		l = r;
		r = tmp;
	}
	int maskSet = (int)(pow(2, r+1) -1) ^ (int)(pow(2, l) -1);
	y = y | (x & maskSet);

	return y;
}


Consider the statement 
result = a ? b : c; 
Implement the above statement without using any conditional statements.

Type pool[2] = {b, c};
	Type result = pool[ a == 0];

//logical right shift in c
//Generate MAX_INT (Max signed int value) using bitwise operators. Should work in 32 and 64 bit processors	google

int lsr(int x, int n)
{
  return (int)((unsigned int)x >> n);
}

private int maxInt()
{
int a=-1;
a=a>>>1; //thisis logical right shift works in java
int int_max = (unsigned int) (~0) >> 1 //works in c

return a;
}

Given an 32-bit integer X, swap the i-th and j-th bit.
swap(int n,int i,int j) 
{ 
if( (n & 1<<i)>>i ^ (n & (i<<j))>>j) ) // if bits i and j are different 
{ 
n^= 1<<i; 
n^= 1<<j; 
} 
return n; 
}

Given an 8 bits, give the range of integers it can cover.
Range will be from -128 to 127 
general rule for n bits is--> from -2^(n-1) to (2^(n-1))-1

Range could also be 0 to 255 if you only choose unsigned integers 
In this case, from 0 to (2^n)-1


Calculate number of zeros in a given integer.
Is it to find the zeros in binary format? 
If yes then: 

count = 0 
while (n>0) { 
count = count + !(n&1) 
n=n>>1 //Right shift by 1 
} 
return count 

To find in decimal format the 

count = 0 
while (n>0) { 
count = count + (n%10>0 ? 0 : 1) 
n = n/10; 
} 
return count
while(num!=0)
    {
        k=num%10;

        if(k==0)
        count++;


        num=num/10;

    }
    cout<<"\n"<<count;
    
int main()
{
	

	return 0;
}
