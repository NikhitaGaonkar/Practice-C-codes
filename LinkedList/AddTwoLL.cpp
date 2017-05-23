#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
}node;

node *newNode(int data)
{
  node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data= data;
  temp->next = NULL;
  return temp;
}
node *addTwoNos(node *first, node *second)
{
  node *temp, *prev;
  node *result = NULL;
  int carry=0, sum=0;

  while(first!=NULL || second!=NULL)
  {
    sum = carry + (first? first->data: 0) + (second? second->data :0);
 
    carry = (sum >= 10) ? (sum/10): 0;
    
    sum = (sum >= 10) ? (sum % 10): sum;

    temp = newNode(sum);

    if(result == NULL)
      result = temp;
    else
      prev-> next = temp;

    prev = temp;
    
    if(first)   
      first = first->next;
    if(second)
      second = second->next;
  }
  //store the final carry
  if(carry>0)
    temp->next = newNode(carry);
 // prev->next = temp;
  return result; 
}

int main()
{
	return 0;
}
