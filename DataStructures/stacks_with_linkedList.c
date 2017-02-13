#include<stdio.h>
#include<stdlib.h>

/*
   STACK WITH LINKED LIST
   
   add a new node at the beginning of the list 
*/

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Stack
{
	Node *first; //pointer 1st element or top
	int size; //no of elements in the stack
	
}Stack;

Stack *create_stack()
{
	Stack *S = malloc(sizeof(Stack));
	S->first = NULL;
	S->size = 0;
	return S;	
}

void push(Stack *S, int elem)
{
	Node *new_node = malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Malloc failed");
		return;
	}
    new_node->data = elem;
	new_node->next = S->first;
	S->first = new_node;
	S->size++;	
}

int pop(Stack *S)
{
	if(S->first == NULL)
	{
		printf("Stack is empty");
		return -1;
	}
	Node *temp = S->first;
	int item = temp->data;
	S->first= S->first->next;
	S->size--;
	free(temp);
	return item;
}

int top(Stack *S)
{
	if(S->first == NULL)
	{
		printf("Stack is empty");
		return -1;
	}
    return (S->first->data);	
	
}

int main()
{
        Stack *S = create_stack();
        push(S,7);
        push(S,5);
        push(S,21);
        push(S,-1);
		printf("Size = %d \n",S->size);
        printf("Top element is %d\n",top(S));
        pop(S);
        printf("Top element is %d\n",top(S));
        pop(S);
        printf("Top element is %d\n",top(S));
        pop(S);
        printf("Top element is %d\n",top(S));

}



