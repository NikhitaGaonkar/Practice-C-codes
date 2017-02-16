#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Stack{
	
	int capacity;
	int size;
	int *elements;
}Stack;

Stack *create_stack(int max_elems)
{
	if(max_elems<=0)
	  return NULL;
  	Stack *s = (Stack *)malloc(sizeof(Stack));
  	s->capacity = max_elems;
  	s->size = 0;
  	s->elements = malloc(sizeof(int)*max_elems);
  	return s;
}

void push(Stack *s, int elem)
{
	if( s== NULL || s->size == s->capacity)
	  return;
	  	printf("Push : %d \n",	top_of_stack(s) );
	s->elements[s->size++] = elem;	//size initialized to 0 in create
	printf("Push : %d \n",	top_of_stack(s) );
}

int pop(Stack *s)
{
	if(s==NULL || s->size == 0)
	  return;
	  
	return s->elements[s->size--];
}

int top_of_stack(Stack *s)
{
  if(s== NULL || s->size == 0)
    return -1;
    
  return s->elements[s->size-1]; //size is incremented in push
  
}

typedef struct Queue{
	
	Stack *stack;
	Stack *aux_stack;
	
}Queue;

Queue *create_queue(int max_elements)
{
	Queue *q = malloc(sizeof(Queue));
	q->stack = create_stack(max_elements);
	q->aux_stack = create_stack(max_elements);
	return q;
}

void enqueue(Queue *q, int elem)
{
	push(&q->stack, elem);
}

void dequeue(Queue *q)
{
	if(q==NULL)
	  return;
	  
	if(q->stack == NULL && q->aux_stack == NULL)
	   return;
	   
	int x;
	if(q->aux_stack->size ==0)
	{
		while(q->stack->size !=0)
		{
			x= pop(&q->stack);
			push(&q->aux_stack, x);
		}
	}
	x= pop(&q->aux_stack);
}

int get_front_elem(Queue *q)
{
	if(q==NULL)
	  return;
	  
	if(q->stack == NULL && q->aux_stack == NULL)
	   return;
	   
	int x;
	//printf("I am here \n");
	printf("I am here %d \n",q->aux_stack->size );
	if(q->aux_stack->size == 0)
	{
		printf("I am here \n");
		while(q->stack->size !=0)
		{printf("I am here \n");
			x= pop(&q->stack);
				printf("top : %d \n",	top_of_stack(&q->stack) );
			push(&q->aux_stack, x);
		}
	}
	x= top_of_stack(&q->aux_stack);
	return x;
}


int main() {

   Queue *q= create_queue(100000);
   int m=0;
   scanf("%d", &m);
   int q0, i,j;
   for(q0=0; q0<m; q0++)
   {
   	 scanf("%d", &i);
   	 if(i== 1)
   	 {
   	 	scanf("%d", &j);
   	 	enqueue(q,j);
	 }
	 //else if(i == 2)
	   //dequeue(q);
	 else printf("%d \n",get_front_elem(q));
   }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

