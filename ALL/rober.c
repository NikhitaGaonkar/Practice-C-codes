#include<stdio.h>
#include<stdlib.h>

int rob(int money[])
{
	int n = sizeof(money);///sizeof(int); 
	printf("%d \n", n); //gives the number of elements in an array
	if(money== NULL|| n==0 )
	return 0;
	
	int *dp =  malloc(sizeof(int)*(n));
	memset(dp, 0, sizeof(int)*(n));
	if(n==0) return 0;
	if(n==1) return money[0];
	if(n==2) return max(money[0], money[1]);
	
	dp[0] = money[0];
	dp[1] = max(money[0], money[1]);
	
	int i;
	for( i =2; i<n+1; i++)
	 dp[i]=  max(dp[i-1], dp[i-2]+money[i]);
	 
	return dp[n-1];	
}

//circular array...1st is neighbour of last...
int robII(int money[])  
{
	int n = sizeof(money);///sizeof(int); 
	printf("%d \n", n); //gives the number of elements in an array
	if(money== NULL|| n==0 )
	return 0;
	
	if(n==0) return 0;
	if(n==1) return money[0];
	if(n==2) return max(money[0], money[1]);

	int *dp =  malloc(sizeof(int)*(n));
	memset(dp, 0, sizeof(int)*(n));
	
	//include 1st element and not the last element
	dp[0] = money[0];
	dp[1] = max(money[0], money[1]);
	
	int i;
	for( i =2; i<n-1; i++)    //n-1 explains excluding last element
	 dp[i]=  max(dp[i-1], dp[i-2]+money[i]);
	
	int *dr =  malloc(sizeof(int)*(n));
	memset(dr, 0, sizeof(int)*(n)); 
	
	//exclude 1st element and include the last element
	dr[0] = 0;   //setting 1st element at 0...means adding 0..as good as excluding it
	dr[1] = money[1];
	
	for( i =2; i<n; i++)
	 dr[i]=  max(dr[i-1], dr[i-2]+money[i]);
	
	printf("%d \n",dp[n-2]);
    printf("%d \n",dr[n-1]);
	
	return max(dp[n-2],dr[n-1] );	
	
}

int max(int a ,  int b)
{
	return (a>b?a:b);
}

void main()
{
  int money[100]={2,10,72,7,11,29,8,38};
  //printf("enter the array");
  //scanf("%d", money);
  //printf("%d \n", max(9,7));  //testing max
  printf("The max money robbed is %d \n",  rob(money));
  printf("The max money robbed is %d \n",  robII(money));
}

////////////////OUTPUT//////////////
/*
8
The max money robbed is 141
103
139
The max money robbed is 139

*/


