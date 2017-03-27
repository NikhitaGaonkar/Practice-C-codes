#include<stdio.h>
#include<string.h>
/*
The memcpy function is used to copy a block of data from a source address to a destination address. 
void * memcpy(void * destination, const void * source, size_t num);
The idea is to simply typecast given addresses to char *(char takes 1 byte). 
Then one by one copy data from source to destination. 
*/

void myMemCpy(void *dest, void *src, size_t n)
{
   // Typecast src and dest addresses to (char *)
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
 
   // Copy contents of src[] to dest[]
   for (int i=0; i<n; i++)
       cdest[i] = csrc[i];
}
 
// Driver program
int main()
{
   char csrc[] = "GeeksforGeeks";
   char cdest[100];
   myMemCpy(cdest, csrc, strlen(csrc)+1);
   printf("Copied string is %s", cdest);
 
   int isrc[] = {10, 20, 30, 40, 50};
   int n = sizeof(isrc)/sizeof(isrc[0]);
   int idest[n], i;
   myMemCpy(idest, isrc,  sizeof(isrc));
   printf("\nCopied array is ");
   for (i=0; i<n; i++)
     printf("%d ", idest[i]);
   return 0;
}
/*
 memmove()
 
memmove() is similar to memcpy() as it also copies data from a source to destination. 
memcpy() leads to problems when source and destination addresses overlap 
as memcpy() simply copies data one by one from one location to another. For example consider below program.
*/

// A function to copy block of 'n' bytes from source
// address 'src' to destination address 'dest'.
void myMemMove(void *dest, void *src, size_t n)
{
   // Typecast src and dest addresses to (char *)
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
 
   // Create a temporary array to hold data of src
   char *temp = new char[n];
 
   // Copy data from csrc[] to temp[]
   for (int i=0; i<n; i++)
       temp[i] = csrc[i];
 
   // Copy data from temp[] to cdest[]
   for (int i=0; i<n; i++)
       cdest[i] = temp[i];
 
   delete [] temp;
}
 
// Driver program
int main()
{
   char csrc[100] = "Geeksfor";
   myMemMove(csrc+5, csrc, strlen(csrc)+1);
   printf("%s", csrc);
   return 0;
}
/*
Run on IDE
Output:

GeeksGeeksfor
Optimizations:
The algorithm is inefficient (and honestly double the time if you use a temporary array). 
Double copies should be avoided unless if it is really impossible.

In this case though it is easily possible to avoid double copies by picking a direction of copy. 
In fact this is what the memmove() library function does.

By comparing the src and the dst addresses you should be able to find if they overlap.

– If they do not overlap, you can copy in any direction
– If they do overlap, find which end of dest overlaps with the source and choose the direction of copy accordingly.
– If the beginning of dest overlaps, copy from end to beginning
– If the end of dest overlaps, copy from beginning to end
– Another optimization would be to copy by word size. Just be careful to handle the boundary conditions.
– A further optimization would be to use vector instructions for the copy since they’re contiguous.
*/

