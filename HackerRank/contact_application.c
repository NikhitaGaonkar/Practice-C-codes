#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_CHARS 26

typedef struct trie_node{
	int value;
	struct trie_node * children[MAX_CHARS];
}trie_node;


trie_node *get_node()
{
  trie_node *pNode = (trie_node *)calloc(MAX_CHARS, sizeof(trie_node));
  return pNode;	
}

trie_node *initialize()
{
	trie_node *root = get_node();
	root->value = 0; //use this as count
	return root;
}

void insert(trie_node *root, char *key)
{
	if(root == NULL)
	  return;
	int i=0;
	int len = strlen(key);
	int index;
	trie_node *pCrawl = root;
	
	for(i=0; i<len; i++)
	{
		index = (int)(key[i] - 'a');
	    pCrawl->value++; //increase the count of previous node to indicate the no of keys starting from it
		if(pCrawl->children[index] == NULL) 
	      pCrawl->children[index] = get_node();
	    
	    pCrawl = pCrawl->children[index];  
	}
	//mark last node as leaf node
	//pCrawl->value = root->value;
	
}


int get(trie_node *root, char *key)
{
	int len = strlen(key);
	int i = 0;
	int index;
	int count =0;
    trie_node *pCrawl= root;
    
	for(i=0; i<len; i++)
	{
		index = (int)(key[i] - 'a');
		if(pCrawl->children[index] == NULL)
		  return 0;
	  	    
	    if(i == len-1)
	    {
	       count = pCrawl->value;	       
		}
		
		pCrawl = pCrawl->children[index];  
	}
	
	return count;	
}

void add_contact(trie_node *root, char *contact)
{
	insert(root, contact);
}

int find_contact(trie_node *root, char *contact)
{
	return  get(root, contact);
	
}


int main(){
    int n; 
    scanf("%d",&n);
    int a0;
    trie_node *root = initialize();
    
    for(a0 = 0; a0 < n; a0++){
        char* op = (char *)malloc(512000 * sizeof(char));
        char* contact = (char *)malloc(512000 * sizeof(char));
        scanf("%s %s",op,contact);
        if(strcmp(op, "add") == 0)
          add_contact(root, contact);
        else if(strcmp(op, "find") == 0)
          printf("%d\n",find_contact(root, contact));
        
    }
    free(root);
    return 0;
}

