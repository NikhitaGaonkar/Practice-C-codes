#include"vector.h"
#include<string.h>
/*
  Initializes a vector struct
  Allcoate memory to underlying data array  
*/
int vector_init(Vector *vector)
{	
	vector->size = 0;
	vector->capacity = INITIAL_VECTOR_CAPACITY;
	
	vector->data = (data_type*) malloc(sizeof(data_type)* vector->capacity);
	
	if(vector->data == NULL)
	  return 0;
	  
	else return 1;
}

/*
  Appends given value to the vector
  If vector is full, expand data array to accept the value
  Increase the size
*/
void vector_append(Vector *vector, data_type data)
{
	int status=1;
	
	if(vector->size >= vector->capacity)
	  status = vector_increase_capacity_if_full(vector);
	
	if(status)
	  vector->data[vector->size++] = data;
	else
	  printf("No memory, cannot append");
}

/*
  Return value at a given index
*/
int vector_get(Vector *vector, int index)
{
	if(index<0 || index >= vector->size)	
	{
	  printf("Index %d is out of bound", index);
	  exit(1);
	}
	
	return (vector->data[index]);
}

/*
  Set the value at the given index
  If index is large increase the vector capacity 
  Zero fill till the desired index
*/
void vector_set(Vector *vector, int index, data_type data)
{
	//zero fill till the desired index
	while(index >vector->size)
	  vector_append(vector, 0);
	
	vector->data[index] = data;
	vector->size++;
}

/*
  If vector is full, increases the capacity by factor
  Allocated memory to data
  Copies all old elements to new data
*/
int vector_increase_capacity_if_full(Vector *vector)
{
	data_type *new_data;
	
	if(vector->size >= vector->capacity)
	{
		vector->capacity *= GROWTH_FACTOR;
	//	vector->data = realloc(vector->data, sizeof(data_type)* vector->capacity);
		new_data = (data_type*) malloc(sizeof(data_type)* vector->capacity);
		if(new_data == NULL)
		  return 0;
	}
	
	memcpy((void*)new_data, (void*)vector->data, vector->capacity /GROWTH_FACTOR);
	if(vector->data)
	  free(vector->data);
	  
	vector->data = new_data;
	
	return 1;
}

/*
  Free the memory allocated to dat array
*/
void vector_free(Vector *vector)
{
	if(vector->data)
	  free(vector->data);	
}


//driver code to test

int main()
{
	Vector vector;
	int ret = vector_init(&vector);
#if 1	
	int i =0;
	for(i=0; i<9;i++)
	  vector_append(&vector, i);
	
	printf("The data value at index %d : %d ", 8, vector_get(&vector, 8));
	printf("\n");
	printf("\n");
#endif

#if 1	
	vector_set(&vector, 15, 15);
	
	int j =0;
	for(j =0; j<16; j++)
	  printf("The data value at index %d : %d \n", j, vector_get(&vector, j));
#endif	
	return 0;
}
