#include<stdio.h>
#include<stdlib.h>

int find_index(char *str, int start, int end, char *input[])
{
	if(start>end)
	  return -1;
	  
	int mid = (start+end)/2;
	
	//both methods work
	
#if 0
	//handle the empty string
	while(strcmp(input[mid], "")==0)
	  mid++;
#endif

#if 1
    //more effecient is to find the closest string
    int left = mid-1;
    int right = mid+1;
    while(1)
    {
	
    	if(left< start && right>end)
     	   return -1;
    	if((left >= start) && (strcmp(input[left],"")!=0))
    	{
    		mid = left;
    		break;
		}
		if((right <=end) && (strcmp(input[left],"")!=0))
   		{
    		mid = right;
    		break;
		}
		right ++;
		left--;
	}		
#endif
	  
	if(strcmp(input[mid], str)==0)
	  return mid;
	  
	if(strcmp(input[mid], str)==1)
	  return find_index(str, start, mid-1, input);
	else return find_index(str, mid+1, end, input);
	
	return 0;
}
int main()
{
	char *input[] = {"at", "","","","ball","","","car","","","dad","",""};
	char str[] ="ball";
	int index= find_index(str, 0, 12, input);
	printf("%d", index);
	return 0;	
}
