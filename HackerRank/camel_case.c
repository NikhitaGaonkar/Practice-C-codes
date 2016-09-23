#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

bool is_capital(char c)
{
  if(('Z'-c)<0)
      return false;
  return true;
}

int camel_case(char *str)
{
  int count=0;
  int len = strlen(str);
  for(int i=0; i<len; i++)
  {
      if(is_capital(str[i]))
          count++;
  }
    
  return count+1;
}

int main(){
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
    printf("%d", camel_case(s));
    return 0;
}
