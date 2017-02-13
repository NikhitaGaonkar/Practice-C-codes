#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
Alice wrote a sequence of words in CamelCase as a string of letters, , having the following properties:

It is a concatenation of one or more words consisting of English letters.
All letters in the first word are lowercase.
For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.
Given s, print the number of words in s on a new line.

e.g:
saveChangesInTheEditor
5
*/
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
