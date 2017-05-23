#include<stdio.h>
#include<stdlib.h>

int number_of_paths(int m, int n)
{
	//if(m <=0 || n<=0) return 0;
	//map to store results of subproblems
	int map[m][n];
	int i,j ;
	//count of paths to reach any cell in 1st column is one
	for(i =0; i<m; i++)
	  map[i][0] = 1;
	//count of paths to reach any cell in 1st column is one
	for(j =0; j<n; j++)
	  map[0][j] = 1;
	  
	for(i= 1; i<m; i++)
	{
		for(j =1; j<n; j++)
		  map[i][j] = map[i-1][j] + map[i][j-1]; //+ map[i-1][j-1] <--if diagonal movement is allowed
	}
    return map[m-1][n-1];
}


int main(void)
{
	printf("Paths to 3,3 = %d \n", number_of_paths(3,3));	
	printf("Paths to 3,2 = %d \n", number_of_paths(3,2));
	printf("Paths to 1,1 = %d \n", number_of_paths(1,1));
	printf("Paths to 0,-1 = %d \n", number_of_paths(0,-1));
	return 0;
}
