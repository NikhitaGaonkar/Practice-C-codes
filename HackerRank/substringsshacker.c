#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void SparseArrays(char Query[][20],char Input[][20], int Q, int N)
{
   int count[10]={0}; 
   int i, j,k;
   for(i=0; i<N; i++)
   {
       for(j=0; j<Q; j++)
       {
           if((strcmp(Input[i], Query[j])==0))
          {   
               count[j]++; 
          }
       }
   }
   for( k = 0; k<Q; k++)
   {
       printf("%d \n", count[k]); 
   }
  
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N= 10, Q=10;
    scanf("%d", &N);
    printf("%d \n", N);
    char Input[N][20];
    char Query[Q][20];
    int i,j;
    for(i=0; i<N; i++)
    {  
    scanf("%20s", Input[i]);
        //fgets(Input[i], sizeof(Input[i]), stdin);
         printf("The variable entered was: %s\n",Input[i]);
    }
    scanf("%d", &Q);
    printf("%d \n", Q);
    for(j=0; j<Q; j++)
    {
        fgets(Query[j], sizeof(Query[j]), stdin);  
        
    }
    SparseArrays(Query,Input,Q,N);
    return 0;
}
