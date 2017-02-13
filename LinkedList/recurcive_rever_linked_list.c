#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

void revrse(node **head)
{
	node *curr = *head;
	node * prev = NULL;
	node *next = NULL;
	
	while(curr)
	{
	  next = curr->next;
	  curr->next = prev;
	  prev = curr;
	  curr = next;
	}
	*head = prev;
}
void recursive_reverse(node **head, node *curr, node *prev)
{
	if(curr->next == NULL)
	{
		*head = curr; //save last node as head
		curr->next = prev;
		return;
	}
	node *next = curr->next;
	curr->next = prev;
	recursive_reverse(head, next, curr);
}

void reverse_linked_list(node **head)
{
  if(head == NULL)
    return;
  recursive_reverse(head, *head, NULL);
}

// A utility function to create a new node
node *newNode(int key)
{
    node *temp = (struct Node*)malloc(sizeof(node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printlist(node *head)
{
    while(head != NULL)
    {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(2);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
    
    printlist(head1);
    revrse(&head1);
    printlist(head1);
    reverse_linked_list(&head1);
    printlist(head1);
    
	return 0;
}


