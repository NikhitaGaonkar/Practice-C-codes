#include<stdio.h>
#include<stdlib.h>

void remove_duplicates(char *str, int len)
{
	if(len <= 1 || str == NULL) return;
	if(len == 2)
	{
		if(str[0] == str[1])
			str[1] = '\0';
	}
	
	int *map = calloc(256, sizeof(int));
    //input and result index
	char ch;
	int i_index=0, r_index=0;
	while(*(str + i_index))
	{
		ch = *(str + i_index);
		if(map[ch] == 0)
		{
			*(str + r_index) = ch;
			++r_index;
			map[ch] = 1;
		}
		++i_index;
	}
	//null terminate the string
	*(str + r_index) = '\0';
}