#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Returns n'th term in look-and-say sequence
int countnndSay(int n)
{
    // Base cases
    if (n == 1)      
	{
	  printf("1");
	  return 1;
	}
    if (n == 2) 
	{
	  printf("11");
	  return 1;
    } 
    // Find n'th term by generating all terms from 3 to
    // n-1.  Every term is generated using previous term
    char str[100] = "11"; // Initialize previous term
    int i;
    char count[10];
    for (i = 3; i<=n; i++)
    {
        // In below for loop, previous character
        // is processed in current iteration. That
        // is why a dummy character is added to make
        // sure that loop runs one extra iteration.
        strcat(str, "$");
	    //printf("here");	
        int len = strlen(str);
 
        int cnt = 1; // Initialize count of matching chars
        char tmp[100] = ""; // Initialize i'th term in series
 
        // Process previous term to find the next term
        int j;
        for (j = 1; j < len; j++)
        {
            // If current character does't match
            if (str[j] != str[j-1])
            {
                
                itoa(cnt, count, 10);
				// Append count of str[j-1] to temp
                strcat(tmp,count);
               // tmp += cnt + '0';
               count[0]= str[j-1];
                // Append str[j-1]
               strcat(tmp, count);
                //tmp += str[j-1];
 
                // Reset count
                cnt = 1;
            }
 
            //  If matches, then increment count of matching
            // characters
            else cnt++;
        }
 
        // Update str
        strcpy(str,tmp);
    }
 
    printf("the string is %s",str);
    return 1;
}
 
// Driver program
int main()
{
    int N = 3;
   // cout << countnndSay(N) << endl;
   countnndSay(N);
    return 0;
}
