/*For programmers, the most important elements to be aware of are:

The run time of malloc does not usually depend on the size of the chunk, but might depend on how many free chunks there are. 
free is usually fast, regardless of the number of free chunks. Because calloc clears every byte in the chunk, the run time depends on chunk size (as well as the number of free chunks).
realloc is sometimes fast, if the new size is smaller than the current size, or if space is available to expand the existing chunk. 
If not, it has to copy data from the old chunk to the new; in that case, the run time depends on the size of the old chunk.

Boundary tags: When malloc allocates a chunk, it adds space at the beginning and end to store 
information about the chunk, including its size and the state (allocated or free). 
These bits of data are called “boundary tags”. Using these tags, malloc can get from any chunk to the previous chunk and the next chunk in memory. 
In addition, free chunks are chained into a doubly-linked list, so each chunk contains pointers to the next and previous chunks in the “free list”.
The boundary tags and free list pointers make up malloc’s internal data structures. 
These data structures are interspersed with program data, so it is easy for a program error to damage them.

Space overhead: Boundary tags and free list pointers take up space. The minimum chunk size on most systems is 16 bytes.
So for very small chunks, malloc is not space efficient. If your program requires large numbers of small structures, it might be more efficient to allocate them in arrays.

Fragmentation: If you allocate and free chunks with varied sizes, the heap will tend to become fragmented. That is, the free space might be broken into many small pieces. 
Fragmentation wastes space; it also slows the program down by making memory caches less effective.

Binning and caching: The free list is sorted by size into bins, so when malloc searches for a chunk with a particular size, 
it knows what bin to search in. So if you free a chunk and then immediately allocate a chunk with the same size, malloc will usually be fast.
*/

/*
ref: https://github.com/danluu/malloc-tutorial/blob/master/malloc.c
	 https://danluu.com/malloc-tutorial/
*/
#include<assert.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

/*
NOTE: 
sbrk(0) returns a pointer to the current top of the heap. 
sbrk(foo) increments the heap size by foo and returns a pointer to the previous top of the heap.
*/

//a simple malloc(), no bookkeeping so cannot free.
void *malloc(size_t size)
{
	void *ptr = sbrk(0);
	void *request = sbrk(size);
	//check id sbrk failed, (void*)-1 is an error returned by sbrk system call
	if(request == (void*)-1)
		return NULL;
	//debug
	assert(p ==  request)
	return p;
}

//malloc() with free realloc and calloc
//we will create a linked list of block 
typedef struct block_meta{
	size_t size; //size of block allocated 
	struct block_meta *next; //pointer to next block
	int free; //flag to identify if free
}block_meta;

#define META_SIZE sizeof(struct block_meta)

void *gbase = NULL;

//iterate through blocks till we find one large enough
block_meta *find_free_block(block_meta **last, size_t size)
{
	block_meta *current = gbase;
	//iterate through the list to get the free block
	while(current && (current->free && current->size >= size))
	{
		*last = current;
		current = current->next;
	}
	return current;
}

//request a new block
void *request_space(block_meta *last, size_t size)
{
	block_meta *block = sbrk(0);
	void *request = sbrk(size + META_SIZE);
	//check if sbrk failed 
	if(request == (void*)-1)
		return NULL;
	//debug
	assert((void*)block == request);
	//NULL at 1st time
	if(last)
		last->next = block;
	//set the block meta data
	block->free = 0;
	block->size = size
	block->next = NULL;
	
	return block;
}

//wohooo malloc!
/*
If it's the 1st call ie gbase is NULL then request space
else try to find a free block , if not found, request space
*/
void *malloc(size_t size)
{
	if(size <= 0) return NULL;
	block_meta *block = NULL;
	if(gbase == NULL)
	{
		block = request_space(gbase, size);
		//if request failed
		if(block == NULL) return NULL;
		gbase = block;
	}
	else
	{
		block_meta *last = gbase;
		block = find_free_block(&last, size);
		if(block == NULL)
		{
			//failed ot find free block , request new
			block = request_space(last, size);
			//request failed
			if(block == NULL) return NULL;
		}
		// return block+1 because we want to return a pointer to the region after block_meta. 
		//Since block is a pointer of type struct block_meta, +1 increments the address by one sizeof(struct(block_meta)).
		return block + 1;
	}
}

//void free(void *ptr)

block_meta *get_block_ptr(void *ptr)
{
	return (block_meta)*ptr -1;
}

void free(void *ptr)
{
	if(ptr == NULL)return;
	block_meta *block_ptr = get_block_ptr(ptr);
	if(block_ptr) 
		block_ptr->free = 1;
}


//calloc
void *calloc(size_t num_elem, size_t size_elem)
{
	size_t size = num_elem * size_elem;
	void *ptr = malloc(size);
	memset(ptr, 0, size);
	return ptr;
}


void *realloc(void *ptr, size_t size)
{
	if(ptr == NULL)
		return malloc(size); //behave just like malloc
	block_meta *curr_bloc_ptr = get_block_ptr(ptr);
	if(curr_block_ptr->size >= size) 
		return ptr; //nothing to do, unless we implement split
	//we need to reallocate
	block_meta *new_ptr = malloc(size);
	if(new_ptr == NULL) return NULL;
	//copy existing elements
	memcpy(new_ptr, ptr, curr_bloc_ptr->size);
	free(ptr);
	return new_ptr;
}



























