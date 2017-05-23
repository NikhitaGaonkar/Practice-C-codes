#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
  int data;
  struct Node *next;
}node;

node *addSameLengthList(node *head1, node *head2, int *carry)
{
   if(head1 == NULL)
     return NULL;
   int sum;
   node *res = (struct Node *)malloc(sizeof(struct Node));
   res->next = addSameLengthList(head1,head2, &carry);
   sum = head1->data + head2->data +carry;
   carry = sum/10;
   sum = sum%10;
   
   res->data = sum;
   return res;
}	

void addCarryToRemainingElements(node *head1, node *curr, int *carry, node **result)
{
  int sum;
  if(head1 != curr)
  {
    addCarryToRemainingElements(head1->next, curr, &carry,result);
    sum = head1->data + *carry;
    *carry = sum/10;
    sum= sum%10;

    push(result, sum);
  }
}


void AddTwoLinkedList(node* head1, node *head2, node **result)
{
  if(head1 == NULL)
  {
    *result = head2;
     return;
  }
  if(head2 == NULL)
  {
    *result = head1;  
     return;
  }
  
  int length1 = getLen(head1);
  int length2 = getLen(head2);

  int carry = 0;

  if(length1 ==length2)
    *result = addSameLengthList(head1, head2, &carry, result);
  else
  {
    //length of 1st list has to be larger
    if(length1 < length2)
      swap(head1, head2);
   
    int diff = abs(length1 - length2);
   
    node *curr;
    for(curr = head1; diff--; curr = curr->next);
   
    *result = addSameLengthList(curr, head2, &carry, result);

    addCarryToRemainingElements(head1, curr, &carry, result);

 }
 //if there is final carry
 if(carry)
  push(result, carry);
}


