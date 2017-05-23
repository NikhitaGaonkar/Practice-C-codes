#include<stdio.h>
#include<stdlib.h>

#define N 4

int is_valid_path(int x, int y , int maze[N][N])
{
  if(x >=0 && x<=N-1 && y>=0 && y<=N-1 && maze[x][y]==1)
    return 1;

  return 0;	
}

int find_path(int maze[N][N], int x, int y, int sol[N][N])
{
	if(x== N-1 && y ==N-1)
	{
	  sol[x][y]=1;
	  return 1;
	}
	
	if(is_valid_path(x,y,maze) == 1)
	{
		sol[x][y]=1;
		//now move forward in x direction ie right
		if(find_path(maze, x+1, y, sol) == 1)
		  return 1;
		
		//moving right did not yield soln ,so move down 
		if(find_path(maze, x, y+1, sol) == 1)
		  return 1;
		  
		//nothing gives soln, mark sol array as 0 and backtrack
		sol[x][y]=0;
		return 0;
	}
	
	return 0;
}

void print_path(int sol[N][N])
{
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j =0; j<N; j++)
		  printf("%d ", sol[i][j]);
		printf("\n");
	}
}
int solve_maze(int maze[N][N])
{
	int sol[N][N]= {{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},};
	
	if(find_path(maze, 0,0, sol) == 0)
	{
	  printf("No path");
	  return 0;
	}
	print_path(sol);  
	return 1;
}

int main()
{
	int maze[N][N] = { {1, 0, 0, 0},
       				   {1, 1, 0, 1},
					   {0, 1, 0, 0},
			           {1, 1, 1, 1}};
			           
    int ret = solve_maze(maze);
    
	return 0;
	
}
