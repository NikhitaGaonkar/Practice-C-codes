#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* 
Consider the following series: 

A := 1 
B := A*2 + 2 
C := B*2 + 3 and so on... 
Write a program that: 

-outputs the number corresponding to a given letter; 

-given a string of letters like 'GREP', computes the sum of the numbers corresponding 
 to all the letters in the string (i.e., G + R + E + P), as given by the above series; and 

-given a large number (that would fit into a standard 32-bit integer), 
 finds the shortest string of letters corresponding to it. You may use a greedy approach for the last part.
 Compute the values of the numbers corresponding to letters as and when required and DO NOT pre-compute beforehand and store them in a data structure.
 */
 
 int compute_value(char ch)
 {
	if(ch == 'A')
      return 1;
    int ich = (int)ch;
    //printf("%c\n", ch);
    int val = compute_value((char)(ich - 1))*2 + ich - 64;
	return val;
 }
 
 int compute_string_value(char *str)
 {
	 int len = strlen(str);
	 int i, sum =0;
	 for(i=0; i<len; i++)
	   sum += compute_value(str[i]);
     return sum;
 } 
 
 char *value_to_string(char * str, int val)
 {
	 int i, k=0;
	 for(i=0; i< 'Z'-'A'; ++i)
	 {
		 if(val == 0)
			 break;
		 
		 int char_val = compute_value('Z' - i);
		 int quo = val/char_val;
		 
		 if(quo)
		 {
			 str[k++] = ('Z' - i) +'0';
			 val -= char_val; 
		 }
	 }
	 str[k] = "\0";
	 
	 return str;
     	
 }
 
 int main()
 {
	 char ch = 'C';
	 char mystr[26];
	 int val = compute_value(ch);
	 printf("%d \n", val);
	 char str[] = "ABC";
	 printf("%d \n", compute_string_value(str));
	 
	 value_to_string(mystr,16);
	 printf("%s\n", mystr);
	 return 0;
 }
