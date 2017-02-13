// C/C++ program to segregate even and odd nodes in a
// Linked List
#include <stdio.h>
#include <stdlib.h>
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};
 
 /* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
void segregateEvenOdd(struct node *head)
{
    struct node *odd = NULL;
    struct node *even = NULL;
    struct node *odd_prev = NULL;
    struct node *even_prev = NULL;
    
    struct node *pCrawl = head;
    
    while(pCrawl!= NULL)
    {
    	if(pCrawl->data % 2 == 0)
    	{
    		
    		if(even == NULL)
    		{
    			even_prev = pCrawl;
    			even= pCrawl;
    			//even->next = NULL;
			}
			else
			{
			    even_prev->next = pCrawl;
			    even_prev = pCrawl;
			}
			
		}
		
		else
		{
		   if(odd == NULL)
		   {
		   	  odd = pCrawl;
		   	  odd_prev = pCrawl;
		   }	
		   else
		   {
		   	  odd_prev->next = pCrawl;
			  odd_prev = pCrawl;
		   }
		}
    	
    	pCrawl = pCrawl->next;
	}
	
	odd_prev->next = NULL;
	even_prev->next = NULL;
	printf("Odd \n");
	printList(odd);
	printf("\n");
	printf("Even \n");
	printList(even);
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning  */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 

 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Let us create a sample linked list as following
      0->2->4->6->8->10->11 */
 
    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);
 
    printf("\nOriginal Linked list \n");
    printList(head);
 
    printf("\nModified Linked list \n");
    
	segregateEvenOdd(head);
 
    
    
 
    return 0;
}
