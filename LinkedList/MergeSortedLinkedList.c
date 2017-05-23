#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

Node *merge_sorted_linked_list(Node *head1, Node *head2)
{
	Node *new_head;
	Node *temp;
	if(head1 == NULL)
	 return head2;
	
	if(head2 == NULL)
	  return head1;
	
	//choosing the head for merged list  
	if(head1->data < head2->data)
	{
	  new_head = head1;
	  head1 = head1->next;
	}
	else
	{
		new_head = head2;
		head2 = head2->next;
	}

    temp = new_head;
    
    while(head1 != NULL && head2 != NULL)
    {
    	if(head1->data < head2->data)
    	{
		  temp->next = head1;
		  head1= head1->next;
    	}
    	else if(head2->data < head1->data)
    	{
    	  temp->next = head2;
    	  head2 = head2->next;
		}
		else  //remove duplicates
		{
		  temp->next = head1;
		  head1= head1->next;
    	  head2 = head2->next;
		}
		
		 temp =temp->next;
	}
	//copy remaining elements of list one
	while(head1 != NULL)
	{
		 temp = head1;
		 temp= temp->next;
    	 head1= head1->next;
	}
	//copy remaning elements of list two
	while(head2 != NULL)
	{
	  temp = head2;
      temp = temp->next;
	  head2 = head2->next;	
	}
	
	return new_head;
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

void print_list(Node *head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}


int main() 
{
    Node* result = NULL;
    Node* a = NULL;
    Node* b = NULL;
 
    //Created lists, a: 1->3->15,  b: 2->3->20 
    push_node(&a, 15);
    push_node(&a, 3);
    push_node(&a, 1);
 
    push_node(&b, 20);
    push_node(&b, 3);
    push_node(&b, 2);

    result = merge_sorted_linked_list(a, b);
 
    printf("Merged Linked List: \n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    print_list(result);
 
    return 0;
}

