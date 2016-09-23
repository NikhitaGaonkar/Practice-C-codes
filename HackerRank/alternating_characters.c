#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int alternating_char(char str[])
{
   int n = strlen(str);
   int count =0;
   for(int i= 0; i<n ; i++)
   {
       if(str[i] == 'A' && str[i+1] == 'A')
       {
           count++;
       }
       else if(str[i]== 'B' && str[i+1] == 'B')
         count++;
   }
    return count;
}

int main(){
    int n; 
    scanf("%d",&n);
    char* B = (char *)malloc(10240 * sizeof(char));
    for(int i =0; i<n ; i++)
    {    
     scanf("%s",B);
     //printf("%s \n", B);
     printf("%d \n",alternating_char(B));
    }
    return 0;
}

