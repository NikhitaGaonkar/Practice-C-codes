#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int noOfGemElement(char a[], char b[], char *intersection)
{
    int map[26]={0};
    char *ptr = intersection ;
    int lenA = strlen(a);
    int lenB = strlen(b);    
    int i, j;
    for(i=0; i<lenA; i++)
        map[a[i] - 'a'] =1;
    
    for(j =0; j<lenB; j++ )
    {
        if(map[b[j]-'a'] == 1)
        {
          *ptr++ = b[j];
          map[b[j]-'a'] = 0;
        }
    }
    *ptr = '\0';
    int gemElements = strlen(intersection);
    return gemElements;
}

int main() {

    int N =0;
    char inputString1[100];
    char inputString2[100];
    char intersection[100];
    
    scanf("%d", &N);
    if(N<= 1)
        printf("invalid input");
    scanf("%100s", inputString1);
    scanf("%100s", inputString2);
    int gemElem = noOfGemElement(inputString1, inputString2, intersection);
    int i;
    for(i= 2; i< N; i++)
    {
      scanf("%100s", inputString1);
      strcpy(inputString2, intersection);
      gemElem = noOfGemElement(inputString1, inputString2, intersection);  
    }
    printf("%d", gemElem);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
/*
int main() {

    char inter[10];
    char a[]="abcd";
    char b[]= "aabcc";
    int i = noOfGemElement(a, b,inter );
    printf("%d", i);
    
    printf("%s", inter);
  
    return 0;
}
*/
