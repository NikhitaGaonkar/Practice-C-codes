#include<stdio.h>
#include<stdlib.h>

int reverse_bits(int a, int i, int j)
{
	int left = ~0;
	left = left <<(j+1);
	int right = ((1<<i)-1);
	int mask = left | right;
	a = a^(~mask);
	return a;
	
}
void print_binary(int n)
{
  char buffer [33];
  itoa (n,buffer,2);
  printf ("binary: %s\n",buffer);
  /*while (n) {
    if (n & 1)
        printf("1");
    else
        printf("0");

    n >>= 1;
  }
  void print_binary(unsigned n) { 
if(n) 
{ 
print_binary(n >> 1); 
cout << (n%2) ; 
} 
}
  */
}

int main()
{
  int a = 0xFF;
  print_binary(a);

  //printf("%d \n", a);
  int m = reverse_bits(a, 1, 5);
  print_binary(m);
  
  printf("\n");
  int n = 0x55;
  print_binary(n);
  printf("0x%2X",~n); //else xor with 0xFFFFFFFF
}
