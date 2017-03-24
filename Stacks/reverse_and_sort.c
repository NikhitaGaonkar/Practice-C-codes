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

//iterative
Stack *sort_stack(Stack *s)
{
	//assuming have the stack size
	if(s == NULL || s->size == 1) return s;
	//create a result stack
	Stack *r = create_stack();
	int temp =0;
	
	while(!isEmpty(s))
	{
		temp = pop(s);
		if(!isEmpty(r) && top(r) > temp) //for the ascending order top(r) < temp
			push(s, pop(r)); //push the top element to s
    
		push(r, temp);
	}
	free(s); // free memory allocated to s
	return r;
}

//recursive
//hold all values in recursion stack until stack becomes empty
//push elem in sorted order
void sort_stack(Stack **s)
{
	if((*s) == NULL) return;
	if(!isEmpty(*s))
	{
		int temp = pop(s);
		sort_stack(s);
		sorted_push(s, temp);
	}
}

void sorted_push(Stack **s, int elem)
{
	if(isEmpty(*s) || elem > top(*s))
	{	
		push(*s, elem);
		return;
	}	
	int temp = pop(*s);
	sorted_push(s,elem);
	push(*s, temp);
}

//reverse a given stack
void reverse_stack(Stack **s)
{
	if((*s) == NULL) return;
	if(!isEmpty(*s))
	{
		int temp = pop(*s);
		reverse_stack(s);
		insert_at_bottom(s, temp);
	}
}

void insert_at_bottom(Stack **s, int elem)
{
	if((*s) == NULL) return;
	
	if(isEmpty(*s))
		push(*s, elem);
	
	if(!isEmpty(*s))
	{
		int temp = pop(*s);
		insert_at_bottom(s, elem);
		push(*s, temp);
	}
	
}

i/p 
-3
14
18
-5
30

o/p
30
18
14
-3
-5
    
	
	