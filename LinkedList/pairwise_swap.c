#include<stdio.h>
#include<stdlib.h>

/*   
   Given a singly linked list, write a function to swap elements pairwise.
   For example, if the linked list is 1->2->3->4->5->6->7 then the function should change it to 2->1->4->3->6->5->7, 
   and if the linked list is 1->2->3->4->5->6 then the function should change it to 2->1->4->3->6->5
*/

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node* new_node(int data)
{
	Node *temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void reverse_list(Node **head)
{
	Node *prev = NULL, *curr = *head, *next;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
}

void printlist(Node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		if(head->next) printf("-> ");
		head = head->next;
	}
	printf("\n");
}


void pairwise_swap(Node **head)
{
	if(*head == NULL || (*head)->next == NULL)
		return;
	
	Node *curr = (*head)->next;
    Node *prev = *head, *next= NULL;
	*head = curr;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		if(next == NULL || next->next == NULL )
		{	
			prev->next = next;
			break;
		}
		prev->next = next->next;
		prev = next;
		curr = next->next;
	}
}

// Driver program
int main()
{
	Node *head = new_node(1);
	head->next = new_node(2);
	head->next->next = new_node(3);
	head->next->next->next = new_node(4);
	head->next->next->next->next = new_node(5);

	printlist(head); // Print original list
	pairwise_swap(&head);
	printlist(head); // Print modified list
	return 0;
}
