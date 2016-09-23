#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void super_reduced_string(char *str)
{
	int len = strlen(str);
	int i =1;
	for(i=1; i<len; i++)
	{
		printf("%s %d \n", str,i);
		if(str[i]==str[i-1])
		{
			memmove(&str[i-1], &str[i+1], len-i);
			i=1;
			//i--;
		}
	}
}

int main()
{
	char a[]="aaabccbd";
	super_reduced_string(a);
	printf(" reduced string----> %s ", a);
	return 0;
}
