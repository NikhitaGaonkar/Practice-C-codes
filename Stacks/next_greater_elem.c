#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node * next;
}Node;

typedef struct Stack{
	
	Node *first; //head node 
	int size; //size of the stack
}Stack;

void next_greater_elem(int *arr, int size)
{
	if(arr == NULL || size == 0) return;
	
	if(size == 1)//only one element
	  printf("%d", -1);
	Stack *s = create_stack();
	int elem=0, next=0;
	//push 1st element in stack
	push(s, arr[0]);
	for(int i=1; i<size; ++i)
	{
		next = arr[i];
		if(!isEmpty(s))
		{
			elem = pop(s);
			while(elem < next)
			{
				printf("%d", next);
				if(!isEmpty(s))
				  elem = pop(s);
			    else break;
			}
			if(elem > next)
			{
				push(s, elem);
			}
		}
		push(s, next);
	}
	//last elem is always -1
	while(!isEmpty(s))
	{
		elem = pop(s);
		printf("%d", -1);
	}
}

Test cases:
arr[] ={}; //nothing
arr[] ={1}; //-1
arr[] = {1,2,3,4,5}; //same as arr
arr[] = {100, 26, 16, 10, 4}; //all -1
arr[] = {4, 10, 6,25}; //10 25 25 -1