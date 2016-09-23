#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int message_altered(char S[])
{
    int len = strlen(S);
    int i =0, count = 0;
    while(S[i] != '\0')
    {
        if(S[i] != 'S')
            count++;
        if(S[i+1] != 'O')
            count++;
        if(S[i+2] != 'S')
            count++;
            
        i += 3;
    }
    return count;
}
int main(){
    char* S = (char *)malloc(10240 * sizeof(char));
    scanf("%s",S);
    
    printf("%d", message_altered(S));
    
    return 0;
}

