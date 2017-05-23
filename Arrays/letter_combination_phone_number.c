#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char key_pad[10][5] ={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void print_letter_combination_phone_number(int number[], int size, int curr_digit, char result[])
{
	
	int i;
	
	if(curr_digit == size)
	{
		printf("%s ", result);
		return;
	}
	
	for(i=0; i< strlen(key_pad[number[curr_digit]]); ++i)
	{
		result[curr_digit] = key_pad[number[curr_digit]][i];
		print_letter_combination_phone_number(number, size, curr_digit+1, result);
		if(number[curr_digit]==0  || number[curr_digit]==1)
		  return;
		
	}
}

void letter_combination_phone_number(int number[], int size)
{
	char result[size+1];
	result[size]='\0';
	print_letter_combination_phone_number(number, size, 0, result);
}


//Driver program
int main(void)
{
    int number[] = {2, 3, 4};
    int n = sizeof(number)/sizeof(number[0]);
    letter_combination_phone_number(number, n);
    return 0;
}
