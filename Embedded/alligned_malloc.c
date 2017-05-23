#inlclude<stdio.h>
#include<stdlib.h>

void *aligned_malloc(size_t required_bytes, size_t align_size)
{
	void *ptr1, *ptr2, *aligned_ptr;
	int align_mask = align_size-1;
	
	ptr = (void*)malloc(required_bytes+align_size+sizeof(void*));
	if(ptr==NULL)
	  return NULL:
	
	ptr2= ptr1+sizeof(void*);
	
	aligned_ptr = ptr2+
}
typedef struct Node{
	int data;
	struct Node *next;
}Node;


Node *add_node(Node *head)
node->data
