/*
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
CHAR_BIT	8						Defines the number of bits in a byte.

SCHAR_MIN	-128					Defines the minimum value for a signed char.
SCHAR_MAX	+127					Defines the maximum value for a signed char.
UCHAR_MAX	255						Defines the maximum value for an unsigned char.

CHAR_MIN	-128					Defines the minimum value for type char and its value will be equal to SCHAR_MIN if char represents negative values, otherwise zero.
CHAR_MAX	+127					Defines the value for type char and its value will be equal to SCHAR_MAX if char represents negative values, otherwise UCHAR_MAX.
MB_LEN_MAX	16						Defines the maximum number of bytes in a multi-byte character.

SHRT_MIN	-32768					Defines the minimum value for a short int.
SHRT_MAX	+32767					Defines the maximum value for a short int.
USHRT_MAX	65535					Defines the maximum value for an unsigned short int.

INT_MIN	   -2147483648				Defines the minimum value for an int.
INT_MAX		+2147483647				Defines the maximum value for an int.
UINT_MAX	4294967295				Defines the maximum value for an unsigned int.

LONG_MIN	-9223372036854775808	Defines the minimum value for a long int.
LONG_MAX	+9223372036854775807	Defines the maximum value for a long int.
ULONG_MAX	18446744073709551615	Defines the maximum value for an unsigned long int

*/



int reverse(int x) {
    
 if(x==0 || x>INT_MAX || x<INT_MIN)
   return 0;
      
 int sign = 1;
 if(x<0)
   sign = -1; 
 x= abs(x);
 int val =0;
 int val_test =0;
 while(x>0) 
 {
   val_test = val*10;
   //test overflow
   if(val_test/10 != val)
     return 0;
   val = val_test + (x%10);
   x = x/10;	
 } 
 val = sign * val;

 return val;  
    
}
