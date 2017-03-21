#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int value_of(char ch)
{
	if(ch == 'I')
	  return 1;
	else if(ch== 'V')
	 return 5;
	else if(ch== 'X')
	 return 10;
	else if(ch== 'L')
	 return 50;
	else if(ch== 'C')
	 return 100;
	else if(ch== 'D')
	 return 500;
	else if(ch== 'M')
	 return 1000;
	else	 
	return -1;
}


int roman_to_int(char *s)
{
	int len = strlen(s);
	int integer = 0, i=0;
	int val =0;
	
	for(i=len-1; i>=0; --i)
	{
		val = value_of(s[i]);
		if((i<len-1) && (value_of(s[i])< value_of(s[i+1])))
		  val *= -1;
		integer += val;
	}
	
	return integer;
	
}


// Driver Program
int main()
{
    // Considering inputs given are valid
    char str[] ="MCMIV";
    printf("Integer form of Roman Numeral is %d ", roman_to_int(str));
 
    return 0;
}
