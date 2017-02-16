#include<stdio.h>
#include<stdlib.h>

/*
   PRIORITY QUEUES USING LINKEDLIST
   
   Add data at rear and remove from front
   While adding check the priority
   
*/


typedef struct Node{

	int data;
	struct Node *next;
}Node;

typedef struct Queue{
	
	int size;
	Node *rear;
	Node *front;
}Queue;

Queue *create_queue()
{
  Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
  q->size = 0;
  q->rear = q->front = NULL;

  return q;
}

void enqueue_with_priority(Queue *q, int data)
{
  if(q->rear == NULL) //if queue is empty create a 1st node 
  {
   	q->rear= (struct Node*)malloc(sizeof(struct Node));
  	q->rear->data = data;
  	q->rear->next = NULL;
  	q->front = q->rear;
  }
  else
  {
  	Node *temp = (struct Node*)malloc(sizeof(struct Node));
  	temp->data = data;
  	temp->next = NULL;
	
	//if its greater than last element , simply add at the end
	if(data > q->rear->data)
	{
		q->rear->next = temp;
  	    q->rear = temp;
	}
    else //traverse the list 
	{
		Node *curr = q->front;
		Node *prev = curr;
		
		while(curr!= NULL && data > curr->data )
		{
			prev = curr;
			curr = curr->next;
		}
		//we are at the begining of the list
		if(curr == q->front)
		{
			temp->next = curr;
			q->front = temp;
		}
		//we are at the end of the list
		else if(curr == NULL )
	    {
			prev->next = temp;
		}
		else //we are in the middle of the list
		{
			prev->next = temp;
			temp->next = curr;
		}
	}
	
  }  
  q->size++;
}

//same as regular queue
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

int is_empty(Queue *q)
{
	return (q->front == NULL);
}

int main()
{
	int max_elem = 4;
	Queue *q = create_queue();
	enqueue_with_priority(q, 10);
	enqueue_with_priority(q, 5);
	enqueue_with_priority(q, 50);
	enqueue_with_priority(q, -15);
	enqueue_with_priority(q, 4);

	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	//enqueue_with_priority(q, 44);
	//dequeue(q);
    //printf("The front element: %d", queue_front_element(q));
	return 0;
}
