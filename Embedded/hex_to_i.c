#include<stdio.h>
#include<stdlib.h>

/*
Hex to Int

How to Calculate Hexadecimal to Decimal

Hex is a base 16 number and decimal is a base 10 number. We need to know the decimal equivalent of every hex number digit. 
See below of the page to check the hex to decimal chart. 
Here are the steps to convert hex to decimal:

Get the decimal equivalent of hex from table.
Multiply every digit with 16 power of digit location. 
(zero based, 7DE: E location is 0, D location is 1 and the 7 location is 2)
Sum all the multipliers.

Here is an example:
7DE is a hex number
7DE = (7 * 162) + (13 * 161) + (14 * 160) 
7DE = (7 * 256) + (13 * 16) + (14 * 1) 
7DE = 1792 + 208 + 14 
7DE = 2014 (in decimal number)

Hex System
Hex, or hexadecimal, is a number system of base 16. This number system is especially interesting 
because in our casually used decimal system we have only 10 digits to represent numbers. As hex 
system has 16 digits, the extra needed 6 digits are represented by the first 6 letters of English alphabet. 
Hence, hex digits are 0,1,2,3,4,5,6,7,8 and 9 A,?B,?C,?D,?E,?F. This number system is the most 
commonly used in mathematics and information technologies. I.e. in html programming colors can be 
represented by a 6-digit hexadecimal number: FFFFFF represents white, 000000 represents black, and so on.

*/
int is_digit(int c)
{
	return (c>= '0' && c<= '9');
}

int is_alpha(int c)
{
	return((c>= 'a' && c<= 'f')	|| (c>= 'A'&& c<='F'));
}

unsigned long hex_to_i(const char* instr, int byte_count)
{
	unsigned long val =0;
	byte_count *= 2;  //convert byte count to nibble count
	
	int i=0;
	for(i=0; i< byte_count; i++)
	{
		char ch = tolower(instr[i]);
	//	printf("%c \n", ch);
		if(is_digit(ch))
		  val = val * 16 + ch - '0';
		else if(is_alpha(ch))
		  val = val * 16 + ch - 'a' + 10;
		else return 0;

	}
	return val;
}

int main()
{
	char a[]= "07DE";// "FFFF";
	printf("%ld", hex_to_i(a,2 ));
	return 0;
}
