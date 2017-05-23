#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char *dictionary[] = {"i", "like", "ice", "icecream","mango", "man", "go"};
const int dict_size = 7;

int dict_contains(char *str)
{
	int i =0;
	for(i =0; i < dict_size; i++)
	  if(strcmp(dictionary[i], str) == 0)
	    return 1;
			
	return 0;
}
/*A simple implementation of strncpy() might be: https://linux.die.net/man/3/strncpy

char *strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

   for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for ( ; i < n; i++)
        dest[i] = '\0';

   return dest;
}*/

char *substr(char *str, int pos, int len)
{
	if(str == NULL) return NULL;
	char *buff = malloc(sizeof(char) * (len+1));
	strncpy(buff, (str + pos),len);
	/*int i =0;
	for(i= pos; i<=len; i++)
	  buff[i] = str[i];*/
	*(buff+len) ='\0';
	printf("%s\n", buff);
	return buff;
}
#if 0
int word_break(char *str)
{
	int len = strlen(str);
	int i=0;
	for(i=1; i<=len; i++)
	{
		if(dict_contains(substr(str,0,i))  && word_break(substr(str,i, len-1)))
		  return 1;
	}
	return 0;
}
#endif


//dyanmic programming
int word_break(char *str)
{
	if(str == NULL) return 0;
	
	int len = strlen(str);
	if(len == 0) return 0;
	
	int *table = calloc(len+1,sizeof(int));
	int i, j;
	for(i=1; i<=len; i++)
	{
		if(table[i] == 0 && dict_contains(substr(str, 0, i)))
		  table[i] = 1;
		  
		if(table[i]==1)
		{
			//we reached the end of string
			if(i == len) return 1;
			
			for(j=i+1; j<=len; j++)
			{
				if(table[j]==0 && dict_contains(substr(str, i, j-1)))
				  table[j] = 1;
				  
				if(j==len && table[j] ==1)
				  return 1;	
			}
		} 
	}
	
	return 0;
}


int main()
{
	printf("mango is present %d", word_break("mango"));
	return 0;
}
