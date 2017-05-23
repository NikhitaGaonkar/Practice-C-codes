#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse_string(char *str)
{
     
	char *start = str;
	char *end = str;
	if(str)
	{
	  while(*end)
	  {
		end++;
      }
    }
    --end;

	char temp;
	while(end>start)
	{
		temp = *start;
		*start++ = *end;
		*end -- =temp;
	}
}

void my_iota(int num, char *str, int base)
{
	int i =0;
	int sign = 0;
	int rem =0 ;
	
	if(num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return; //str;
	}
	
	if(num<0 && base == 10)
	{
		sign =1;
		num = -num;
	}
	
	while(num)
	{
		rem = num%base;
		str[i++]= (rem>9) ? rem -10 +'a' : rem + '0';
		num /= base;
	}
	
	if(sign == 1)
	  str[i++]= '-';
			
    str[i]= '\0';	
	reverse_string(str);
	//return str;
}

int main()
{
	char str[100];
	my_iota(-1991,str, 10);
//	printf("%s", my_iota(-1991,str, 10));
	printf("%s", str);
	return 0;
}
