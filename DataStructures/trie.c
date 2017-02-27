#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
  TRIES
  
  efficient information retrieval data structure 
  trie from retrieval but pronounced try to avoid confusion with tree
  
  key   	value
  by      	  4
  sea    	  6
  sells  	  1
  she 		  2
  shells      3
  shore       7
  the         5
  
  key is a sequence of characters from root to value
  value is in node corresponding to last character of the key
  
										root
									/.... |.....\
								   /	  |		 \
								   b	  |       t
								   |      |       |
								   y 4    |       h
										  |       |
										  s       e 5
										 / \
										/   \
									   e     h
									  / \    |  \
								   6 a  l  2 e   o 
								        |    |   |
										l    l   r
										|    |   |
									  1 s    l   e 7
									         |
											 s 3
											 
	NOTE: Neither keys nor the characters are explicitly stored
	      each node has an array of links and a value
		  characters are simply defined by link index
		  
	
*/

#define MAX_CHARS 256  //extended ASCII

typedef struct trie_node{
	
	int value; //indicates end of a key
	struct trie_node *children[MAX_CHARS];  //array of pointers to next level of trie nodes (links)
}trie_node;

trie_node *get_node()
{
	trie_node *pNode = (trie_node *)malloc(sizeof(trie_node));
	if(pNode)
	{
		int i;
		pNode->value =0;
		for(i=0; i<MAX_CHARS; i++)
			pNode->children[i] = NULL;
	}
	return pNode;	
}

trie_node *initialize()
{
	trie_node *root = get_node();
	root->value = 0; 
	return root;
}


/*
  The key character acts an index into children array
  If the input key is new or an extension of existing key, we need to
  construct non-existing node of key and set the value at the end of the input key
  If the input key is prefix of excisting key, we just set the value at the end of the key  
*/
void insert(trie_node *root, char *key, int value)
{
	if(root == NULL)
		return;
	int i=0, index;
	trie_node *pCrawl = root;
	root->value++; //count of keys in the trie
	int len = strlen(key);
	
	
	for(i=0; i<len; i++)
	{
		index = (int)key[i];
		if(pCrawl->children[index] == NULL)
			pCrawl->children[index] = get_node();
		
		//points to array of new node if created else existing node
		pCrawl = pCrawl->children[index];
	}
	//assign the value at the last character of key
	pCrawl->value = value;
}

/*
  compare characters and move down
  the search can terminate in two cases
  case1: lack of string 
        if value of last node is non-zero, then the key exists 
		else return NULL
  
  case2: lack of key in trie
        if link is null i.e. the next char is doesn't exist, return NULL
*/
int get(trie_node *root, char *key)
{
	int len = strlen(key);
	int i = 0;
	int index;
	int count =0;
    trie_node *pCrawl= root;
    
	for(i=0; i<len; i++)
	{
		index = (int)key[i];
		if(pCrawl->children[index] == NULL)
		  return 0;
	  	    
	    pCrawl = pCrawl->children[index];  
	}
	if(pCrawl->value == 0)
		return 0;
	else
        return pCrawl->value;		
}


int main()
{
	char keys[][8] ={"she", "shells", "the", "by"};
	trie_node *trie = initialize();
    insert(trie, keys[0], 2);
	insert(trie, keys[1], 3);
    insert(trie, keys[2], 5);
	insert(trie, keys[3], 4);

    printf("%d\n", get(trie, keys[0]));
	printf("%d\n", get(trie, keys[1]));
	printf("%d\n", get(trie, keys[2]));
	printf("%d\n", get(trie, keys[3]));
	
	return 0;
}













































