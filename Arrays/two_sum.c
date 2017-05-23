#include<stdlib.h>
#include<stdio.h>

#define MAX 100000

int *two_sum(int numbers[], int size, int target)
{
	int i =0, temp =0;
	int map[MAX] ={0};
	int *output = malloc(sizeof(int)*2);
	
	for(i =0; i<size; i++)
	{
		temp = target - numbers[i];
		if(temp >=0 && map[temp] == 1)
		{
			output[0] = numbers[i];
			output[1] = temp;
			return output;
		}
		map[numbers[i]] = 1;
	}
	return output;
}

int *two_sum_II(int numbers[], int size, int target)
{
	int temp =0;
	int l = 0;
	int r = size-1;
	int *output = malloc(sizeof(int)*2);
	
	while(l < r)
	{
		temp = numbers[l] + numbers[r];
		if(temp == target)
		{
			output[0] = numbers[l];
			output[1] = numbers[r];
			return output;
		}
		else if(temp > target)
		  r--;
		else
		  l++;
	}
	return output;
}


int main()
{
	int numbers[] = {1, 455, 50, 10, 99, 47};
	int numbers2[] = {1, 10, 47, 50, 99, 455};
	int target = 465;
	/*
	sizeof is a compile time opration so if you try to find the size
	in two_sum you will get 2, coz in the function it is integer pointer
	*/
	int size = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d \n", size);
	int *output = two_sum(numbers, size, target);
	if(output)
	{
		printf("%d \n", output[0]);
		printf("%d \n", output[1]);
	}
	
	printf("If array is sorted\n");
	int *output2 = two_sum_II(numbers, size, target);
	if(output2)
	{
		printf("%d \n", output2[0]);
		printf("%d \n", output2[1]);
	}
	return 0;
}
