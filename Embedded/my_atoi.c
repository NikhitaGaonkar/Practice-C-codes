#include<stdlib.h>
#include<stdio.h>

int my_atoi(char *str)
{
  int sign = 1; //intializingt to positive
  int result = 0;
  int i =0;

  if(str[0] == '-')
  {
    sign = -1;
    ++i;
  }
  while(str[i] != '\0')
  {
    result = result*10 + str[i] -'0';
    ++i;
  }

  return (result * sign);
}

int main()
{
	char a[]= "-1991";
	printf("%ld \n", my_atoi(a));
	int n = my_atoi(a);
	n +=n;
	printf("n is %d \n ", n);
	return 0;
}
