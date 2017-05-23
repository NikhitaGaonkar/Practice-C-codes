#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	Node *next;
}node;


int isPalindromeIterative(node *head)
{
	node *slw_ptr= head, *fast_ptr = head;
	node *prev_slw_ptr;
	node *mid_ptr, *second_half;
	
	bool result = false;
	
	if(head!=NULL && head->next !=NULL)
	{
		while(fast_ptr->next !=null)
		{
			fast_ptr = fast_ptr->next->next;
		    prev_slw_ptr= slw_ptr;
			slw_ptr = slw_ptr->next;
		}
		
		if(fast_ptr !=NULL)
		{
			mid_ptr = slw_ptr;
			slw_ptr = slw_ptr->next;
		}
		
		second_half = slw_ptr
		prev_slw_ptr->next = NULL;
		
		reverse(&second_half);
		result = compare(head, second_half);
		
	}
	
}
