#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int string_consrtuction_cost(char str[])
{
  // count the no of different characters in the string
  //if the character repeats it is a substring (any substring the question says), so no cost
  int len = strlen(str);
  int dollar =0;
  int i =0;
  int map[26] = {0}; 
  
  for(int i =0; i<len; i++)
  {
    if(map[str[i] -'a'] == 0)
    {
      dollar++;
      map[str[i] - 'a'] = 1;
    }
  }
   
  return dollar;
}

int main(){
    int n; 
    scanf("%d",&n);
    for(int a0 = 0; a0 < n; a0++){
        char* s = (char *)malloc(10240 * sizeof(char));
        scanf("%s",s);
        printf("%d \n",string_consrtuction_cost(s));
    }
    return 0;
}
