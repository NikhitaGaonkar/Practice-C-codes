#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkIfPalindrome(int lb, int ub, char str[])
{
	int len= ub-lb+1;
  	while(lb<ub)
  	{
  	 	if(str[lb] != str[ub])
  	 	{
  	 	  return 0;
		}
	    lb++;
	    ub--;
	}
	
	return len;
}

void printPalindrome(int lb, int ub, char str[])
{
	int i=0;
	for(i = lb; i<ub; i++)
	  printf("%c", str[i]);
}

void longestPalindromicSubstring(char arr[])
{
	int lb=0, ub=0;
	int i, j;
	int maxlen=0;
	int size = strlen(arr);
    int len1=0, len2=0;
    
	for(i=0; i<size; i++)
	{
		for(j=i+1; j<size; j++)
		{
			len1 = checkIfPalindrome(i,j-1,arr);
			if(len1 > maxlen)
		    {
			   maxlen = len1;
			   ub = j;
			   lb = i;
			}
			//len2 = checkIfPalindrome(j,size-1,arr);
			
			/*if(len1!= 0 || len2!=0)
		    {
		    	int temp = len1>len2 ? len1: len2 ;
		    	if(temp > maxlen)
		        {
				   maxlen = temp;
				   ub = j;
				   lb = i;
				   //printf("here");
			    }
			}*/
		}
	}
	//printf("%d %d ", lb, ub);
	printPalindrome(lb, ub, arr);	
	
}

int main()
{
	//char arr[]= "abcdcdcabc";
	char arr[]= "geeksskeegfor";
	longestPalindromicSubstring(arr);
	return 0;
}
