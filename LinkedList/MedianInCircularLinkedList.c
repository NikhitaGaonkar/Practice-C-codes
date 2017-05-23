#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
}Node;

int median_in_circular_sorted_list(Node *head)
{
	bool is_identical = true;
	Node *start = head, *curr = head;
	
	do{
		if(curr->data != curr->next->data)
		  is_identical = false;
		
		//start points to the last or greatest element in the list
		//at the end of loop
		if(start->data <= start->next->data)
		  start= start->next;
		  
	    curr = curr->next;
		
	}while(curr != head);
	
	//start->next is begining of the list
	start= start->next;
	//printf(" start %d \n ", start->data);
	
	if(is_identical)
	  return curr->data;
	  
	//finding the median
	Node *slw = start;
	Node *fast = start;
	
	
	do{
	  slw = slw->next;
	  fast = fast->next->next;
	}while(fast != start && fast->next !=start);

	return slw->data;
	
}

//driver code
void push_node(Node **head_ref, int data)
{
	//adding node at begining of the linked list
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

int main() 
{
    int result =0;
    Node* a = NULL;
    
#if 1     
    //Created lists, a: 1->2->3->4->5->6->7->1,    
    push_node(&a, 7);
    push_node(&a, 6);
    push_node(&a, 5);
    push_node(&a, 4);
    push_node(&a, 3);
    push_node(&a, 2);
    push_node(&a, 1);
#endif

#if 0
    //to test identical
    push_node(&a, 20);
    push_node(&a, 20);
    push_node(&a, 20);
    push_node(&a, 20);
    push_node(&a, 20);
    push_node(&a, 20);
    push_node(&a, 20);
#endif
    Node *last = a;
    
    while(last->next != NULL)
      last = last->next;
    
    last->next = a;
    
    Node *head = a->next->next->next;
    //printf("head %d \n", head->data);
    
	result = median_in_circular_sorted_list(head);
    printf("The median is : %d", result);
 
    return 0;
}

