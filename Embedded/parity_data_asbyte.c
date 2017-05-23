# include <stdio.h>
# define  bool int
 
/* Function to get parity of number n. It returns 1
   if n has odd parity, and returns 0 if n has even
   parity 
   Parity: Parity of a number refers to whether it contains an odd or even number of 1-bits.
   The number has “odd parity”, if it contains odd number of 1-bits and is “even parity” if it contains even number of 1-bits.
   */
bool getParity(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n      = n & (n - 1);
    }        
    return parity;
}
 
/* Driver program to test getParity() */
int main()
{
    unsigned int n = 7;
    printf("Parity of no %d = %s",  n, 
             (getParity(n)? "odd": "even"));
     
    getchar();
    return 0;
}

//create a struct that could be sent over serial, byte by byte, and then re-constructed into a struct.

typedef stuct Data{
	int a;
	int b;
	int c;
	
}Data;

//sending side
Data mydata;
char *bytes = malloc(sizeof(mydata));
memcpy(bytes, &mydata, sizeof(mydata));

//receiving side
Data recdata;
//assuming received data is in bytesrec
char *bytesrec = malloc(sizeof(recdata));
memcpy(&recdata, bytesrec, sizeof(recdata));

//make sure endianness is same on both machines