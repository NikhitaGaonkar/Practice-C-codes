#include <stdio.h>
#include <string.h>

int maxProfit(int prices[]) {

        if(sizeof(prices) == 0) return 0;
		int n =  sizeof(prices);

        int* profit = (int*)malloc(sizeof(int)*n);
		int i;
		memset(profit, 0, sizeof(int)*(n));
        
        int min = prices[0];

        for( i=1; i< n; i++){

            if(prices[i] < min)  min = prices[i];

            profit[i] = max(profit[i-1], prices[i]-min);

        }

        return profit[n-1];

    }
   
   ///////Time complexity O(n) and Space O(1)
    
 /* The function assumes that there are at least two
elements in array.
The function returns a negative value if the array is
sorted in decreasing order.
Returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size)
{
    if(arr_size<=1)
    return 0;
    
int max_diff = arr[1] - arr[0];
int min_element = arr[0];
int i;
for(i = 1; i < arr_size; i++)
{	 
	if (arr[i] - min_element > max_diff)							 
	max_diff = arr[i] - min_element;
	if (arr[i] < min_element)
		min_element = arr[i];					 
}
return max_diff;
} 

int max(int a ,  int b)
{
	return (a>b?a:b);
}

void main()
{
  int money[100]={900,11,600,6,2,100};
  
  printf("The max money  %d \n",  maxProfit(money));
  printf("The max money  %d \n",  maxDiff((money),6));
  
}
