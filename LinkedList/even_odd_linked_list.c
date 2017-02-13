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

void segregateEvenOdd(struct node **head_ref, struct node **even, struct node **odd)
{
	struct node *end = *head_ref;
	struct node *prev = NULL;
	struct node *curr = *head_ref;
    int not_first_odd =1;
    
	/* Get pointer to the last node */
	while (end->next != NULL)
		end = end->next;

	struct node *new_end = end;
	
    //get the first odd
    while (curr->data %2 != 0 && curr != end && not_first_odd ==1)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
		*odd = new_end;
		not_first_odd = 0;
		
	}
	/* Consider all odd nodes before the first even node
	and move then after end */
	while (curr->data %2 != 0 && curr != end)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}

	// 10->8->17->17->15
	/* Do following steps only if there is any even node */
	if (curr->data%2 == 0)
	{
		/* Change the head pointer to point to first even node */
		*head_ref = curr;
        *even = curr;
		/* now current points to the first even node */
		while (curr != end)
		{
			if ( (curr->data)%2 == 0 )
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
			    if(not_first_odd)
			    {
			      *odd = curr;
			    }
				/* break the link between prev and current */
				prev->next = curr->next;

				/* Make next of curr as NULL */
				curr->next = NULL;

				/* Move curr to end */
				new_end->next = curr;

				/* make curr as new end of list */
				new_end = curr;

				/* Update current pointer to next of the moved node */
				curr = prev->next;
			}
		}
		prev->next->next = NULL;
	}

	/* We must have prev set before executing lines following this
	statement */
	else prev = curr;

	/* If there are more than 1 odd nodes and end of original list is
	odd then move this node to end to maintain same order of odd
	numbers in modified list */
	if (new_end!=end && (end->data)%2 != 0)
	{
		prev->next = end->next;
		end->next = NULL;
		new_end->next = end;
	}
	return;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning */
void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
	struct node* even = NULL;
	struct node* odd = NULL;

	/* Let us create a sample linked list as following
	0->2->4->6->8->10->11 */

	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	push(&head, 9);

	printf("\nOriginal Linked list \n");
	printList(head);

	segregateEvenOdd(&head, &even, &odd);
	

	printf("\nModified Linked lists \n");
	printList(even);
	printf("\n");
	printList(odd);

	return 0;
}

