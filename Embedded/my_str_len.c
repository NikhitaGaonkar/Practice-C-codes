#include<stdlib.h>
#include<stdio.h>

//strlen doest not include the null character
int my_str_len(char *str)
{
	int len =0;
	
	while(*(str+len))
	  len++;
	  
	/*
	while(str[len] != '\0')
	  len++
	*/
	return len;
}

int main()
{
	char str[]="hello";
	printf("%d", my_str_len(str));
	return 0;	
}
