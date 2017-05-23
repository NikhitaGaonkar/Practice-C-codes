#include<stdio.h>
#include<stdlib.h>

int my_strstr(char *needle, char *haystack)
{
	if((needle == NULL && haystack == NULL) || (needle == NULL && haystack != NULL))
	  return 1;
	if(needle != NULL && haystack == NULL)
	  return -1;
	
	int i=0, j=0; 
	int len_n = strlen(needle);
	int len_h = strlen(haystack);
	
	if(len_n > len_h)return -1;
		
	for(i=0; ; i++)
	{
		for(j=0; ; j++)
		{
			if(j == len_n) return i; //all chars in needle match, so return current starting point
			if(i+j >= len_h) return -1; //if needle's length exceeds haystack's length
			if(needle[j] != haystack[i+j])
			  break;			
		}
	}
}

int main()
{
	char haystack[] = "Hello World";
	char needle[] = "or";
	printf("%d", my_strstr(needle, haystack));
	return 0;
}
