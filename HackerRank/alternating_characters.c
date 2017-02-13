#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
  Shashank likes strings in which consecutive characters are different. For example, he likes ABABA, while he doesn't like ABAA.
  Given a string containing characters A and B only, he wants to change it into a string he likes. 
  To do this, he is allowed to delete the characters in the string.
  
  Your task is to find the minimum number of required deletions.
  
  AAAA  A, 3 deletions
  BBBBB  B, 4 deletions
  ABABABAB  ABABABAB, 0 deletions
  BABABA  BABABA, 0 deletions
  AAABBB  AB, 4 deletions because to convert it to AB we need to delete 2 A's and 2 B's
*/

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

