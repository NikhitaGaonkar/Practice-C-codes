// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *head = dummy;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        { 
            dummy->next = l1;
            l1 = l1->next;
        }
        else
        {
            dummy->next = l2;
            l2 = l2->next;
        }
        dummy = dummy->next;
    }
    
    while(l1)
    {
        dummy->next = l1;
        l1 = l1->next;
        dummy = dummy->next;
    }
    
    while(l2)
    {
        dummy->next = l2;
        l2= l2->next;
        dummy = dummy->next;
    }
    
    return head->next;
}
/* Takes two lists sorted in increasing order, and merge
their nodes together to make one big sorted list. Below
function takes O(Log n) extra space for recursive calls,
but it can be easily modified to work with same time and
O(1) extra space */
Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if(b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if(a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}

	return result;
}

// The main function that takes an array of lists
// arr[0..last] and generates the sorted output
Node* mergeKLists(Node* arr[], int last)
{
    struct Node *result = NULL;
    int k = 1;
    result = arr[0];
    while(k< last)
    {
        result = SortedMerge(result, arr[k]);
        k++;
        
    }

	return result;
}

// Utility function to create a new node.
Node *newNode(int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	int k = 3; // Number of linked lists
	int n = 4; // Number of elements in each list

	// an array of pointers storing the head nodes
	// of the linked lists
	Node* arr[k];

	arr[0] = newNode(1);
	arr[0]->next = newNode(3);
	arr[0]->next->next = newNode(5);
	arr[0]->next->next->next = newNode(7);

	arr[1] = newNode(2);
	arr[1]->next = newNode(4);
	arr[1]->next->next = newNode(6);
	arr[1]->next->next->next = newNode(8);

	arr[2] = newNode(0);
	arr[2]->next = newNode(9);
	arr[2]->next->next = newNode(10);
	arr[2]->next->next->next = newNode(11);

	// Merge all lists
	Node* head = mergeKLists(arr, k );

	printList(head);

	return 0;
}

