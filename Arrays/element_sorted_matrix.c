#include<stdio.h>
#include<stdlib.h>

//hint: start top right

int element_sorted_matrix(int mat[4][4], int size, int elem)
{
	int row = 0, col=size-1;
	while(row < size && col >=0)
	{
		if(elem > mat[row][col])
		  row++; //go down
		else if(elem < mat[row][col])
		  col--; //go left
		else return 1;
	}
	printf("not found");
	return 0;
}

int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printf("%d \n", element_sorted_matrix(mat, 4, 56));
  
  return 0;
}
