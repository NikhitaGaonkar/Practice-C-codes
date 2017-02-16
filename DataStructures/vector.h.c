#ifndef VECTOR_H
#define VECTOR_H

#include<stdio.h>
#include<stdlib.h>

#define MAX_VECTOR_CAPACITY 200    //maximum capacity
#define GROWTH_FACTOR 2           // typically  1 < GROWTH_FACTOR <=2

typedef data_type int

typedef struct Vector{
	
	int size;      //slots used so far
	int capacity;  //total available slots
	int *data;     //array of integers

}Vector;

int vector_init(Vector *vector);

void vector_append(Vector *vector, data_type data);

int vector_get(Vector *vector, int index);

void vector_set(Vector *vector, int index, data_type data);

void vector_increase_capacity_if_full(Vector *vector);

void vector_free(Vector *vector);

#endif


