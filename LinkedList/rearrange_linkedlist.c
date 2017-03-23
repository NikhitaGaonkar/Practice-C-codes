#include<stdio.h>
#include<stdlib.h>

/*
   Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. 
   Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …
   
   e.g.
   
   1->2->3->4->5
   1->5->2->4->3
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

// Function to rearrange a linked list
void rearrange(Node **head)
{
	if(*head == NULL) return;
	//only one node or only two nodes
	if((*head)->next == NULL || (*head)->next->next == NULL)
		return;
	
	Node *slow = *head;
	Node *fast = *head;
	//split the list
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;		
	}
	
	Node *head1 = *head;
	Node *head2 = slow->next;
	slow->next = NULL;
	
	//reverse the second half 
	reverse_list(&head2);
	
	Node *dummy = new_node(0);
	Node *curr = dummy;
	
	//now do a alternate merge
	while(head1 || head2)
    {
		if(head1)
		{
			curr->next = head1;
			curr = curr->next;
			head1 = head1->next;
		}
		
		if(head2)
		{
			curr->next = head2;
			curr = curr->next;
			head2 = head2->next;
		}
		
	}
	
	*head = dummy->next;
	free(dummy);

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
	rearrange(&head);	 // Modify the list
	printlist(head); // Print modified list
	return 0;
}
