#include<stdio.h>
#include<stdlib.h>

/*
Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. 
Swapping data of nodes may be expensive in many situations when data contains many fields.

It may be assumed that all keys in linked list are distinct.

Examples:

Input:  10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input:  10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input:  10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14
This may look a simple problem, but is interesting question as it has following cases to be handled.
1) x and y may or may not be adjacent.
2) Either x or y may be a head node.
3) Either x or y may be last node.
4) x and/or y may not be present in linked list.

*/
typedef struct Node{
	int data;
	struct Node * next;
}Node;

#define ERROR -1


void swap_nodes(Node **head, int x, int y)
{
	//data to be swapped is same
	if(*head == NULL || x==y) return;
	
	Node *currX = *head, *prevX = NULL;
	Node *currY = *head, *prevY = NULL;
	
	while(currX && currX->data != x)
	{
		prevX = currX;
		currX = currX->next;
	}
	
	while(currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}
	//one or both nodes not present
	if(currX == NULL || currY == NULL)
		return;
	
	if(currX == *head)
		*head = currY;
	else
		prevX->next = currY;
	
	if(currY == *head)
		*head = currX;
	else
		prevY->next = currX;
	
	Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
} 
