#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>


bool is_panagram(char *str)
{
    int Map[26]={0};
    int len = strlen(str);
   
    for(int i =0; i<len; i++)
    {   
      Map[tolower(str[i])-'a'] = 1;
    }
    
    for(int i =0; i<26; i++)
    {
      if(Map[i] == 0)
        return false;
    }  
    return true;
}

int main(){
    char* s = (char *)malloc(10240 * sizeof(char));
    int maxchar = 10000;
    getline(&s, &maxchar, stdin);
       
    if(is_panagram(s))
      printf("pangram");
    else printf("not pangram");
    return 0;
}

