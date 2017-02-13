#include<stdio.h>
#include<stdlib.h>

/*
  Count the no of nodes in a binary tree
*/
typedef struct treeNode{
	
	int data;
	struct treeNode *left;
	struct treeNode *right;
	
}treeNode;

treeNode* insert(treeNode *root, int data)
{
	if(root == NULL)
	{
     root= (treeNode*)malloc(sizeof(treeNode));
     root->left = NULL;
     root->right =NULL;
     root->data = data;
     return root;
    }
    
    if(data > root->data)
      root->right = insert(root->right, data);
    
    else if(data < root->data)
      root->left = insert(root->left, data);
      
    return root;
}

int count_no_of_nodes(treeNode *root)
{
   int c = 1;
   
  if(root == NULL)
    return 0;

  
  c+= count_no_of_nodes(root->left);
  c+= count_no_of_nodes(root->right);
  
  return c;
}

int main()
{
	treeNode *root = NULL;

	root = insert(root, 10);
	root= insert(root, 12);
	root= insert(root, 5);
	root= insert(root, 8);
	root= insert(root, 11);
	 
	int c = count_no_of_nodes(root);
	printf("The no of nodes in binary tree is : %d" ,c);
	
	return 0;
	
}
