#include<stdio.h>
#include<stdlib.h>

/*
   Binary Search Trees
*/
typedef struct treeNode
{
        int data;
		int count; //no of nodes at current node
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

/*
  Insert and Find
  Number of compares for search and insert = 1+depth of node.
  The shape of the tree depends on order of insertion, 
  if the nodes come in order then it is basically no different than a linked list worst height is N
  
  There is 1:1 one correspondence between BST and  quick sort, if there are no duplicates.
  
  Complexity: O(logN)
*/
treeNode * insert(treeNode *node, int data)
{
        if(node==NULL)
        {
               
                node = (treeNode *)malloc(sizeof(treeNode));
                node-> data = data;
                node-> left = node-> right = NULL;
                return node;
        }

        if(data >(node->data))
        {
                node->right = insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = insert(node->left,data);
        }
		
		node->count = 1 + get_size(node->left) + get_size(node->right);
		
        /* Else there is nothing to do as the data is already in the tree. */
        return node;

}

int get_size(treeNode *node)
{
	if(node == NULL) return 0;
    return node->count;
}

//find element iterative and recursive
treeNode *find_iterative(treeNode *node, int data)
{
	treeNode *root = node;
	while(root != NULL)
	{
		if(root->data < data)
			root = root->right;
		else if(root->data > data)
			root = root->left;
		else return root;
	}
    return NULL;
}

treeNode * find_recursive(treeNode *node, int data)
{
        if(node==NULL)
        {
                /* Element is not found */
                return NULL;
        }
        if(data > node->data)
        {
                /* Search in the right sub tree. */
                return find_recursive(node->right,data);
        }
        else if(data < node->data)
        {
                /* Search in the left sub tree. */
                return find_recursive(node->left,data);
        }
        else
        {
                /* Element Found */
                return node;
        }
}

/*
   Ordered Operations
*/

treeNode* find_min(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->left) /* Go to the left sub tree to find the min element */
                return find_min(node->left);
        else 
                return node;
}
treeNode* find_max(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->right) /* Go to the left sub tree to find the min element */
                return find_max(node->right);
        else 
                return node;
}


//depth = no of nodes
int max_depth(treeNode *node)
{
	if(node == NULL)
		return 0;
	int ldepth = max_depth(node->left);
	int rdepth = max_depth(node->right);
	
	if(ldepth < rdepth)
   		return rdepth+1;
	else
	  return ldepth+1;
}

//depth = no of edges
int max_depth_edges(treeNode *node)
{
	if(node == NULL ||(node->left == NULL && node->right == NULL))
		return 0;
	else
	{
		int ldepth = max_depth_edges(node->left);
		int rdepth = max_depth_edges(node->right);
		
		return (ldepth > rdepth ? ldepth+1 : rdepth+1);
	}
	
}


void print_path(int *path, int height)
{
	int i =0;
	for(i=0; i<height; i++)
		printf("%d ", path[i]);
	printf("\n");
}

void print_longest_path(treeNode *root, int *path, int height, int iter)
{
	if(root == NULL)
	  return;
	path[iter++] = root->data;
	
	if(root->left==NULL && root->right == NULL)
	{
		if(iter == height) //print only when number of elements in path is equal to max height
		  print_path(path, height);
	}
	else
	{
		print_longest_path(root->left, path, height, iter);
		print_longest_path(root->right, path, height, iter);
	}

}


/*
 *  Get the number of nodes < key/value.
 *            S  (8) ->size
 *           / \
 *          /   \
 *         /     \
 *     (4)E       W(3)
 *       / \      /\
 *      /   \    /  \
 *  (2)A     H  T    Z (1)
 *      \
 *       C
 *
 *  For E -> rank is get_size(A) = 2
 */
 int get_rank(treeNode *node, int data)
 {
	if(node == NULL) return 0;
	
	if(data < node->data)
		return get_rank(node->left, data);
	else if(data > node->data)
		//root node + no of node less than root+ rank on the right subtree
		return 1 + get_size(node->left) + get_rank(node->right, data);
	else
		//data = node->data
		return get_size(node->left);
	 
 }
 
 
 /*
     Top View
     		 3
		   /   \
		  5     2
		 / \   / \
		1   4 6   7
		 \       /
 		  9     8
    top view: 1->5->3->2->7
 */
void print_left_nodes(treeNode *node)
{
	if(node == NULL) return;
	print_left_nodes(node->left);
	printf("%d ", node->data);
}
void top_view(treeNode *root)
{
	treeNode *temp = root;
	if(root == NULL) return;
	
	print_left_nodes(root->left);
	printf("%d ", root->data);
	//print all right nodes
	while(temp != NULL)
	{
		temp = temp->right;
		printf("%d ", temp->data);
	}
}
void top_view2(treeNode *root)
{
	static treeNode *curr_root = root;
	if(root == NULL) return ;
	//recur on the left
	top_view2(root->left);
	printf("%d ", root->data);
	//for left node curr_root is always previous left node
	//for root it is root
	if(curr_root == root)
	{
		printf("%d ", root->data);
		root = root->right;
		while(root)
		{
			printf("%d ", root->data);
			root = root->right;
		}
	}
}

 
/*
   Delete node in BST.
*/
treeNode * delete_node(treeNode *node, int data)
{
        treeNode *temp;
        if(node==NULL)
        {
                printf("Element Not Found");
        }
        else if(data < node->data)
        {
                node->left = delete_node(node->left, data);
        }
        else if(data > node->data)
        {
                node->right = delete_node(node->right, data);
        }
        else
        {
                /* Now We can delete this node and replace with either minimum element 
                   in the right sub tree or maximum element in the left subtree */
                if(node->right && node->left)
                {
                        /* Here we will replace with minimum element in the right sub tree */
                        temp = find_min(node->right);
                        node -> data = temp->data; 
                        /* As we replaced it with some other node, we have to delete that node */
                        node -> right = delete_node(node->right,temp->data);
                }
                else
                {
                        /* If there is only one or zero children then we can directly 
                           remove it from the tree and connect its parent to its child */
                        temp = node;
                        if(node->left == NULL)
                                node = node->right;
                        else if(node->right == NULL)
                                node = node->left;
                        free(temp); /* temp is longer required */ 
                }
        }
        return node;

}

/*
 *    Tree Traversal
 
 *           7
 *          / \
 *         /   \
 *        4     8    
 *       / \
 *      /   \
 *     1     6
 *
 *   Depth first search
 */

void print_inorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        print_inorder(node->left);
        printf("%d ",node->data);
        print_inorder(node->right);
}

void print_preorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->data);
        print_preorder(node->left);
        print_preorder(node->right);
}

void print_postorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        print_postorder(node->left);
        print_postorder(node->right);
        printf("%d ",node->data);
}



//////////////////////Driver Program///////////////////////
int main()
{
        treeNode *root = NULL;
        root = insert(root, 5);
        root = insert(root, -1);
        root = insert(root, 3);
        root = insert(root, -14);
        root = insert(root, 8);
        root = insert(root, 10);
        root = insert(root, 9);
        root = insert(root, 6);
		
        print_inorder(root);
        printf("\n");
        print_preorder(root);
        printf("\n");
        
        	
        int height = max_depth(root);
        printf("Max height : %d \n", height);
       	printf("Max height edges: %d \n", max_depth_edges(root));
		       
        int rank_root = get_rank(root, 5);
		printf("No of elements less than root %d \n", get_size(root->left));
        
        root = delete_node(root,5);
        root = delete_node(root,-1);
        
		print_inorder(root);
        printf("\n");
		
        treeNode * temp;
        temp = find_min(root);
        printf("Minimum element is %d\n",temp->data);
        temp = find_max(root);
        printf("Maximum element is %d\n",temp->data);

        temp = find_iterative(root,8);
        if(temp==NULL)
          printf("Element 8 not found\n");
        else
          printf("Element 8 Found\n");
        
        temp = find_recursive(root,2);
        if(temp==NULL)
		  printf("Element 2 not found\n");
        else
          printf("Element 6 Found\n");
        
	
		int path[height];
		print_longest_path(root,path, height, 0);
		
		return 0;
	}
