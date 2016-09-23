#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int beautiful_binary_string(char str[], int n)
{
    int i =0, count =0;
    while(str[i] != '\0')
    {
       // printf("%d",str[i]);
        if(str[i] == '0' && str[i+1] == '1' && str[i+2]== '0')
        {
            count++;
            i= i+3;
        }
        else
            i++;
    }
    return count;
}
int main(){
    int n; 
    scanf("%d",&n);
    char* B = (char *)malloc(10240 * sizeof(char));
    scanf("%s",B);
    printf("%d",beautiful_binary_string(B, n));
    return 0;
}

