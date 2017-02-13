#include <limits.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
 
typedef struct entry{
 char *key;
 int value;
 struct entry *next;
}entry;

typedef struct hashtable{
	int size;
	entry **table;
}hashtable;

//
int ht_hash(hashtable *hash_table, char *key)
{
	unsigned long int hashval;
	int i=0;
		
	while(hashval< ULONG_MAX && i<strlen(key))
	{
		hashval = hashval<<8;
		hashval += key[i];
		i++;
	}
	
	return hashval % hash_table->size;
}
//create new hash table
hashtable *ht_create(int size)
{
	if(size < 1)
	  return NULL;
	
	hashtable *hash_table = (hashtable*)malloc(sizeof(hashtable));
	if(hash_table == NULL)
	  return NULL;
	  
	hash_table->table = (entry **)calloc(size, sizeof(entry));
	
	hash_table->size = size;
	
    return hash_table;
}

entry *ht_newpair(char *key)
{
	entry *newpair;
	
	if((newpair = malloc(sizeof(entry)))== NULL)
	  return NULL;
    newpair->key = (char *)malloc(sizeof(char) * strlen(key));
	strcpy(newpair->key, key);
	newpair->value = 1;
    newpair->next = NULL;
    return newpair;
}

//set the hash table
void ht_set(hashtable *hash_table, char *key)
{
	int bin =0;
	bin = ht_hash(hash_table, key);
		
	entry *next = hash_table->table[bin];
	entry *last;
	while(next!= NULL && next->key!= NULL && strcmp(key, next->key)>0)
	{
		last = next;
		next = next->next;
	}
	
	if(next!= NULL && next->key!= NULL && strcmp(key, next->key)==0)
	  next->value++;
	  
	else //generate new pair
	{
        entry *newpair = ht_newpair(key);
		
		if(next == hash_table->table[bin]) 
		{
			newpair->next = next; //key is less than next->key
			hash_table->table[bin] = newpair;
		}
		else if(next == NULL)
		  last->next = newpair;
	    else
	    {
	    	newpair->next = next;
	    	last->next = newpair;
		}
	}
	
}

entry *ht_get(hashtable *hash_table, char *key)
{
	int bin =0;
	bin = ht_hash(hash_table, key);
	entry *pair = hash_table->table[bin];
	
	while(pair!=NULL && pair->key!=NULL &&strcmp(key, pair->key) >0)
	  pair = pair->next;
	  
	if(pair==NULL || pair->key== NULL || strcmp(key, pair->key)!=0)
	  return NULL;
	  
	else return pair;
}

int main(){
    int m; 
    int n; 
    scanf("%d %d",&m,&n);
    char* *magazine = malloc(sizeof(char*) * m);
    int magazine_i ;
    for(magazine_i = 0; magazine_i < m; magazine_i++){
       magazine[magazine_i] = (char *)malloc(10240 * sizeof(char));
       scanf("%s",magazine[magazine_i]);
    }
    char* *ransom = malloc(sizeof(char*) * n);
    int ransom_i;
    for( ransom_i = 0; ransom_i < n; ransom_i++){
       ransom[ransom_i] = (char *)malloc(10240 * sizeof(char));
       scanf("%s",ransom[ransom_i]);
    }
    
    hashtable *hash_table = ht_create(10);
    
    //void ht_set( hashtable_t *hashtable, char *key, char *value )
   
    for(magazine_i = 0; magazine_i < m; magazine_i++)
    {
      ht_set(hash_table,magazine[magazine_i]);	
	}
	//char temp[1024];
	
    for( ransom_i = 0; ransom_i < n; ransom_i++)
    {
    	entry *pair = ht_get(hash_table, ransom[ransom_i]);
    	if(pair == NULL || pair->value==0)
    	{
    	 	printf("No");
		    return 0;
		}
        else
        {
            pair->value--;
        }
            
    	
	}
	
    printf("Yes");
    
    return 0;
}


 
