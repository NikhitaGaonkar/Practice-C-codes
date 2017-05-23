#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
}node;

int ReturnBeginingOfLoop(node *head)
{
  node *slw_ptr = head;
  node *fast_ptr = head;
  
  //find the collision point 
  while(slw_ptr && fast_ptr && fast_ptr->next)
  {
   slw_ptr = slw_ptr->next;
   fast_ptr = fast_ptr->next->next;
   
   if(slw_ptr == fast_ptr)
     break;
  }

  //id no loop found
  if(fast_ptr == NULL || fast_ptr->next == NULL )
    return 0;

  //reset slw_ptr to head
  //moving ine step at a time we reach the collision point 
 // ie begining of the list

  slw_ptr = head;
  while(slw_ptr != fast_ptr)
  {
    slw_ptr = slw_ptr->next;
    fast_ptr = fast_ptr->next;
  }

  return(slw_ptr->data);
}


//driver code

void push_node(node **head_ref, int data)
{
	//adding node at begining of the linked list
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

int main() 
{
    int result =0;
    node* a = NULL;
     
    //Created lists, a: 1->3->15,  
    push_node(&a, 9);
    push_node(&a, 8);
    push_node(&a, 7);
    push_node(&a, 6);
    push_node(&a, 5);
    push_node(&a, 4);
    push_node(&a, 3);
    push_node(&a, 2);
    push_node(&a, 1);
    
    node *temp = a->next->next->next;
    node *last = a;
    
    while(last->next != NULL)
      last = last->next;
    
    last->next = temp;
    
	result = ReturnBeginingOfLoop(a);
    printf("%d", result);
 
    return 0;
}

