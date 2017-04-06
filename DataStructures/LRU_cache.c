#include<stdlib.h>
#include<stdio.h>

/*
  LRU_Cache
  We are given total possible page numbers that can be referred. 
  We are also given cache (or memory) size (Number of page frames that cache can hold at a time). 
  The LRU caching scheme is to remove the least recently used frame when the cache is full 
  and a new page is referenced which is not there in cache. 
  
  Two data structures:
  1) A queue implemented as doubly linked list. The maximum size of the queue is equal to 
  total no of frames available (cache size)
  2) A hash with page number as key and the address of corresponding queue node as value
  
  When a page is referenced, the required page may be in the memory. If it is in the memory,
  we need to detach the node of the list and bring it to the front of the queue.
  If the required page is not in the memory, we bring that in memory. 
  In simple words, we add a new node to the front of the queue and update the corresponding
  node address in the hash. If the queue is full, i.e. all the frames are full, we remove a node 
  from the rear of queue, and add the new node to the front of queue.
*/

typedef struct QNode{
	unsigned page_no;
	struct QNode *prev, *next;
}QNode;

typedef struct Queue{
	unsigned count; //no of frames in the queue
	unsigned number_of_frames; //total number of frames
	QNode *front, *rear;
}Queue;

typedef struct Hash{
	int capacity;//total number of pages that can be referred
	QNode **array; //array of queue nodes
}Hash;

QNode *new_node(unsigned page_no)
{
	QNode *node = (QNode*) malloc(sizeof(QNode));
	node->page_no = page_no;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

Queue *create_queue(int number_of_frames)
{
	Queue * q = (Queue*)malloc(sizeof(Queue));
	q->count = 0;
	q->number_of_frames = number_of_frames;
	q->front = q->rear = NULL;
	return q;
}

Hash *create_hash(int capacity)
{
	Hash *h = (Hash*)malloc(sizeof(Hash));
	h->capacity = capacity;
	h->array = (QNode **)malloc(sizeof(QNode*) * capacity);
	int i;
	for(i=0; i<capacity; ++i)
	  h->array[i] = NULL;
  
	return h;
}

int isQueueFull(Queue *q)
{
	return (q->count == q->number_of_frames);
}

int isQueueEmpty(Queue *q)
{
	return (q->rear == NULL);
}

void enque(Queue *q, Hash *h, unsigned int page_no);
void dequeue(Queue *q);

void reference_page(Queue *q, Hash *h, unsigned int page_no)
{
	if(q == NULL || h == NULL || page_no > h->capacity)
		return;
		
	//node corresponding to the requested page 
	QNode *req_page = h->array[page_no];
	//requested page is not in cache, so bring it in
	if(req_page ==  NULL)
      enque(q, h, page_no);
    //if requested page is not the recent or front node
    else if(req_page != q->front)
	{
		//detach the page
		req_page->prev->next = req_page->next;
		if(req_page->next)
			req_page->next->prev = req_page->prev;
		
		//if the requested page is in the end, 
		//change the rear pointer of the queue
		if(req_page == q->rear)
		{
			q->rear = req_page->prev;
			q->rear->next = NULL;
		}
		//bring the page to the front
		req_page->next = q->front;
		req_page->prev = NULL;
		//change prev of current front
		q->front->prev = req_page;
		//change the front
		q->front = req_page;
	}
	//else nothing to do as node is in front
}

//add node to the front
void enque(Queue *q, Hash *h, unsigned int page_no)
{
	if(q == NULL || h == NULL || page_no > h->capacity)
		return;
	//if queue is full, remove page from the rear
	//remive it from hash table
	if(isQueueFull(q))
	{
		dequeue(q);
		h->array[q->rear->page_no] = NULL;
	}
	QNode *node = new_node(page_no);
	node->next = q->front;
	
	if(isQueueEmpty(q))
	  q->front = q->rear = node;
    else
	{
		q->front->prev = node;
		q->front = node;
	}
	
	//make an entry into hash table
	h->array[page_no] = node;
	q->count++;

}

//remove node from the rear 
void dequeue(Queue *q)
{
	if(q == NULL || isQueueEmpty(q))
		return;
	//only one node
	if(q->front == q->rear)
		q->front = NULL;
	QNode *temp = q->rear;
	q->rear = q->rear->prev;
	if(q->rear)
		q->rear->next = NULL;
	free(temp);
	q->count--;
}

//driver code
int main()
{
    // Let cache can hold X pages
    unsigned int X = 4;
    Queue* q = create_queue( X );
 
    // Let Y different pages can be requested (pages to be
    // referenced are numbered from 0 to 9
    unsigned int Y = 10;
    Hash* hash = create_hash( Y );
 
    // Let us refer pages 1, 2, 3, 1, 4, 5
    reference_page( q, hash, 1);
    reference_page( q, hash, 2);
    reference_page( q, hash, 3);
    reference_page( q, hash, 1);
    reference_page( q, hash, 4);
    reference_page( q, hash, 5);
 
    // Let us print cache frames after the above referenced pages
    printf ("%d ", q->front->page_no);
    printf ("%d ", q->front->next->page_no);
    printf ("%d ", q->front->next->next->page_no);
    printf ("%d ", q->front->next->next->next->page_no);
 
    return 0;
}



























