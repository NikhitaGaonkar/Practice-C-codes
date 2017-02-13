#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Steve has a string,s , consisting of  lowercase English alphabetic letters. In one operation, he can delete any pair of adjacent letters with same value. 
For example, string "aabcc" would become either "aab" or "bcc" after operation.

Steve wants to reduce s  as much as possible. To do this, he will repeat the above operation as many times as it can be performed. 
Help Steve out by finding and printing s in non-reducible form!

Note: If the final string is empty, print Empty String .

e.g:
Steve can perform the following sequence of operations to get the final string:

aaabccddd → abccddd
abccddd → abddd
abddd → abd
Thus, we print abd.

baab 
Empty String

*/
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
