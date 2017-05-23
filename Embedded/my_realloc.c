#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int get_size(void *ptr)
{
	size_t *in = ptr;
	if(in)
	{
		--in;
		return *in;
	}
	return -1;
}
void * my_realloc(void *ptr, int size)
{
	if(!ptr)
	  return NULL;
	
	int ptr_size= 0;
	//get  the size allocated for ptr
	ptr_size = get_size(ptr);
	  
	if(size < ptr_size)
	  return ptr;
	  
	void *new_ptr;
	new_ptr = malloc(size);
	
	if(!new_ptr)
	  return NULL;
	  
	memcpy(new_ptr, ptr, ptr_size);
	
	free(ptr);
	return new_ptr;
}

int main()
{
	char * a = malloc(10);
	printf("%d ", get_size(a));
	
	printf("\n");
	printf("new size");
	
	a = my_realloc(a, 20);
	printf("%d", get_size(a));
	
	return 0;
}


