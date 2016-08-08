#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 200
#define K 3

int buffer[STACK_SIZE * K] ={0};
int stack_ptr[K]= {-1};

void push(int stack_no, int value)
{
	int index = 0;
	
	if(stack_ptr[stack_no] >= STACK_SIZE)
	{
	  printf(" The stack no %d is full", stack_no);
	  return;
	}
	
	stack_ptr[stack_no]++;
	index = STACK_SIZE * stack_no + stack_ptr[stack_no];
	buffer[index]= value;
}

int pop(int stack_no)
{
	if(stack_ptr[stack_no] == -1)
	{
		printf("The stack no %d is empty");
		return -1;
	}
    
    int value = buffer[STACK_SIZE * stack_no + stack_ptr[stack_no]];
    //clear te value
    buffer[STACK_SIZE * stack_no + stack_ptr[stack_no]] = 0;
    stack_ptr[stack_no]--;
    return value;
}

int top_of_stack(int stack_no)
{
	int index = STACK_SIZE * stack_no + stack_ptr[stack_no];
	return buffer[index];
}

int is_empty(int stack_no)
{
	if(stack_ptr[stack_no] == -1)
	  return 1;
	
	return 0;
}

int is_full(int stack_no)
{
	if(stack_ptr[stack_no] >= STACK_SIZE)
	  return 1;
	  
	return 0;
}


int main()
{
	int stack_no_1 =1;
	int stack_no_2 = 2;
	int stack_no_3 =3;
	
	push(stack_no_1, 10);
	push(stack_no_2, 20);
	push(stack_no_3, 30);
	push(stack_no_1, 11);
	push(stack_no_2, 21);
	push(stack_no_3, 31);
	push(stack_no_1, 12);
	push(stack_no_2, 22);
	push(stack_no_3, 33);
	
	printf("top of stack no %d : %d \n",stack_no_1, top_of_stack(stack_no_1));
	printf("top of stack no %d : %d \n",stack_no_2, top_of_stack(stack_no_2));
	printf("top of stack no %d : %d \n",stack_no_3, top_of_stack(stack_no_3));
	
	pop(stack_no_1);
	pop(stack_no_2);
	pop(stack_no_3);

	printf("top of stack no %d : %d \n",stack_no_1, top_of_stack(stack_no_1));
	printf("top of stack no %d : %d \n",stack_no_2, top_of_stack(stack_no_2));
	printf("top of stack no %d : %d \n",stack_no_3, top_of_stack(stack_no_3));
	
	return 0;
	
}
