#include<stdio.h>
#include<stdlib.h>

/*
	Circular buffer of a queue array based.
	http://greenteapress.com/thinkos/html/thinkos011.html
*/
/*
NOTE:
When rear, gets to the end of the array, it wraps around to 0. 
And that’s where we run into a tricky part. 
If we keep adding elements to the queue, eventually front wraps around and catches up with rear. 
But if front == rear, we would incorrectly conclude that the queue was empty.
Hence an extra element.
*/
#define ERROR -1
typedef struct Queue{
	int *array;  //vector of elements
	int size;    //max no of elements
	int front;   //index of oldest
	int rear;	 //index of which to write new element
	Mutex *mx;   //to protect against race condition
	Cond *nonempty //keep the consumer sleeping if nothing to consume
	Cond *nonfull //block the producer until queue is non full or empty
}Queue;

Queue *make_queue(int size)
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL) return NULL;
	q->size = size+1; //inlcude an empty element
	q->array = calloc(q->size, sizeof(int));
	q->front = q->rear =0;
	q->mx = make_mutex();  //refer mutex.c
	return q;
}

int isEmpty(Queue *q)
{
	return (q->rear == q->front);
}

int isFull(Queue *q)
{
	return ((q->rear + 1)% q->size == q->front);
}

void free_queue(Queue *q)
{
	if(q)
	 free(q);
}

//void cb_write(CircularBuffer *cb,int elem)
void enqueu(Queue *q, int elem)
{
	if(q == NULL) return;
	mutex_lock(q->mx);
	while(isFull(q))
	{
		cond_wait(q->nonfull, q->mx);
	}
	q->array[q->rear] = elem;
	q->rear = (q->rear +1) % q->size;
	/*
	for full circular overwrite
	if(q->rear == q->front)
		q->front = (q->front+1) % q->size; 
	*/
	cond_signal(q->nonempty); //signal the consumer that queue is not empty
	mutex_unlock(q->mx);
}

//int cb_read(CircularBuffer *cb)
int dequeue(Queue *q)
{
	if(q ==  NULL) return ERROR;
	mutex_lock(q->mx);
	while(isEmpty(q))
	{
		cond_wait(q->nonempty, q->mx); //wait until not empty
	}
	int item = q->array[q->front];
	q->front = (q->front+1) % q->size;
	cond_signal(q->nonfull); // signal producer queue is not full
	mutex_unlock(q->mx);
	return item;
}


/*
Why is cond_wait inside a for loop rather than an if statement; that is, why do we have to check the condition again after returning from cond_wait?
The primary reason you have to re-check the condition is the possibility of an intercepted signal. 
Suppose Thread A is waiting on nonempty. Thread B adds an item to the queue and signals nonempty.
Thread A wakes up an tries to lock the mutex, but before it gets the chance,
Evil Thread C swoops in, locks the mutex, pops the item from the queue, and unlocks the mutex. Now the queue is empty again, but Thread A is not blocked any more.
Thread A could lock the mutex and returns from cond_wait. If Thread A does not check the condition again, it would try to pop an element from an empty queue, and probably cause an error.
*/

