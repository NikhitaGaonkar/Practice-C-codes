#include<stdlib.h>
#include<stdio.h>

typedef struct tree_node{
	int data;
	struct tree_node *left;
	struct tree_node *right;
}tree_node;

tree_node *bst_to_double_linked_list_util(tree_node *root)
{
	if(root == NULL)
	  return root;
	
	if(root->left != NULL)
	{
		//node returned is roots left
		root->left = bst_to_double_linked_list_util(root->left);
		tree_node * right_most = root->left;
		
		//find the right most node for this root in left subtree
	    while(right_most->right!= NULL)
	      right_most =right_most->right;
	    
	    //at this point right_most->right is null
	    right_most->right = root;
	    root->left = right_most;
	}
	if(root->right != NULL)
	{
		root->right = bst_to_double_linked_list_util(root->right);
		tree_node * left_most = root->right;
		
		//find the left most for this root in right subtree
		while(left_most->left != NULL)
		  left_most= left_most->left;
		
		//left_most->left is null
		left_most->left = root;
		root->right = left_most;
		
	}
	return root;
}

tree_node *bst_to_double_linked_list(tree_node *root)
{
	if(root==NULL)
	  return root;
	
	root= bst_to_double_linked_list_util(root);
	
	//find the head of linked list ie left most node in the tree
	while(root->left != NULL)
	  root= root->left;
	  
	return root;
}

//driver code
tree_node* newNode(int data)
{
    tree_node *new_node = (tree_node*)malloc(sizeof(tree_node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
 
void print_list(tree_node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->right;
    }
}
int main()
{
	//bst
	/*
	                              80
	                40                      90
	        30			50	              85
       20 		 35          60
	 15   25   32	           55		
	
	*/
	
    tree_node *root        = newNode(80);
    root->left        = newNode(40);
    root->right       = newNode(90);
    root->left->left  = newNode(30);
    root->left->right = newNode(50);
    root->left->left->right = newNode(35);
    root->left->left->left =newNode(20);
    root->left->left->left->right =newNode(25);
    root->left->left->left->left =newNode(15);
    root->left->left->right->left  = newNode(32);
    root->left->right->right = newNode(60);
    root->left->right->right->left = newNode(55);
    root->right->left = newNode(85);
 
    // Convert to DLL
    tree_node *head = bst_to_double_linked_list(root);
 
    print_list(head);
 
 	return 0;
	
}
