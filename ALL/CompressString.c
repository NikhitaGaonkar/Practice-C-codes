#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void compressString(char str[])
{
	int len = strlen(str);
	char *new =(char *)malloc(sizeof(char)*len);
	int count =1;
	int i;
	int j=0;
	//char * ptr = str;
	for(i=0; i<len; i++)
	{
	  if(str[i]==str[i+1])
	    count++;
      else
      {
      	new[j++]= str[i];
      	new[j++] = count+'0';
      	count =1;
	  } 
	}
	new[j]= '\0';
	printf("%s", new);
	
}

int main()
{
	char str[]= "aabbbbbccccaaa";
	compressString(str);
	return 0;
}
