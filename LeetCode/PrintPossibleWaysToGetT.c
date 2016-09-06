#include<stdio.h>

void PrintPossibleWaysToPrintT(int T)
{
  int i =1, remainder =0, temp=0 ;	
  for(i=1; i<T-1; i++)
  {
    temp = remainder = T-i;
    printf("%d", i);
    while(remainder)
    {
      printf("+ 1");
      remainder--;
	}
	printf("\n");
	if(temp>=i)
	{
	  printf("%d + %d",i, T-i);
      printf("\n");
	} 
  }
}

int main()
{
  int number;
  printf("Enter a number \n");
  scanf("%d", &number);
  PrintPossibleWaysToPrintT(number);
  return 0;	
}
