#include<stdio.h>
#include<stdlib.h>

#define CIRCULAR (0)

typedef struct Node{

	int data;
	struct Node *next;
}Node;

typedef struct Queue{
	
	int capacity;
	int size;
	Node *rear;
	Node *front;
}Queue;

Queue *create_queue(int max_elements)
{
  Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
  q->capacity = max_elements;
  q->size = 0;
  q->rear =q->front = NULL;

  return q;
}

void enqueue(Queue *q, int data)
{
  if(q->rear == NULL) //if queue is empty
  {
  	q->rear= (struct Node*)malloc(sizeof(struct Node));
  	q->rear->data = data;
  	q->rear->next = NULL;
  	q->front = q->rear;

#ifdef CIRCULAR
  	q->rear->next = q->front;
#endif  	

  	q->size++;
  }
  else
  {
  	if(q->size == q->capacity)
  	{
  		printf("The Queue is full \n");
  		return;
  	}

  	Node *temp = (struct Node*)malloc(sizeof(struct Node));
  	temp->data = data;
  	temp->next = NULL;
  	q->rear->next = temp;
  	q->rear = temp;
  	
#ifdef CIRCULAR
  	q->rear->next = q->front;
#endif
    q->size++;
  }
}

void dequeue(Queue *q)
{
	if(q->front == NULL)
	{
	  printf("The queue is empty \n");
	  return;
	}
	else
	{
		printf("Dequeued value: %d \n", q->front->data);
		//check if only one node
		if(q->front->next != NULL) 
		{
			Node *temp = q->front;
			q->front = q->front->next;
			free(temp);

#ifdef CIRCULAR
  	    	q->rear->next = q->front;
#endif
		}

		else
		{
			free(q->front);
			q->front = NULL;
			q->rear = NULL;
		}

  	    q->size--;
	}
}

int queue_front_element(Queue *q)
{
	if((q->front != NULL) && (q->rear != NULL))
		return q->front->data;
	else
	{
		printf("Trying to get element from empty queue");
		return -1;
	}

}

int main()
{
	int max_elem = 4;
	Queue *q = create_queue(max_elem);
	enqueue(q, 10);
	enqueue(q, 100);
	enqueue(q, 50);
	enqueue(q, -15);
	enqueue(q, 4);

	dequeue(q);
	enqueue(q, 44);
	dequeue(q);
    printf("The front element: %d", queue_front_element(q));
	return 0;
}
