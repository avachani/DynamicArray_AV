// helper.c

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*

Abhi Vachani
Project 2 - Implementation File
Computer Systems Organization
Prof. Kayar

*/





// removeAt
/*

removes an item at the given index
swap the last item of the array with the given index to 
be removed and assign NULL to the last item

*/
void removeAt(DynamicArray* da, int index)
{
	// data[index] is now last element 
	da->data[index] = da->data[da->count - 1];

	// assign last element to null
	da->data[da->count - 1] = NULL;

	// decrease count by 1
	da->count = da->count - 1;


}


// isEmpty
// checks whether the array is empty or not (returns 1 if empty)
int isEmpty(DynamicArray* a)
{
	// if count is 0
	if (a->count == 0) {
		return 1;
	}
	return 0;

}



// pushBack
/* 

checks the limit of your array and inserts an item at the end of the array
(resize the array to 3*capacity if space is not available)

*/
void pushBack(DynamicArray* da, void* obj)
{
	// if array is at limit reallocate memory
	if (da->count == da->capacity) {

		// reallocate data to 3 * capacity
		da->data = (void*) realloc(da->data, 3 * da->capacity);

		// capacity is tripled
		da->capacity = 3*da->capacity;

	}
	
	
	
	// add obj to last element in array
	da->data[da->count] = obj;

	// increase count by 1
	da->count += 1;



}


// clear
// clears the array
void Clear(DynamicArray* da)
{
	// assign every element in array to Null
	int i;
	for (i = 0; i < da->count; i++)
	{
		da->data[i] = NULL;
	}

	// assign count to 0
	da->count = 0;

	// free memory alloc
	memset(da->data,NULL, da->capacity);
	
	/*
 	Originally free'd memory with line of code below, however, 
	upon using CIMS, encountered error and Prof. Kayar 
	instructed me to use memset instead as written above.
	*/
	// free(da->data);

	// assign data to null
	da->data = NULL;

}

//init
/* 

initializes your Dynamic Array by initializing the capacity, allocating the
initial memory dynamically and assigning the function pointers to
corresponding functions

*/
void init(DynamicArray* da)
{
	// initialize count and capacity
	da->count = 0;
	da->capacity = 4;

	// set up func pointers
	da->push_back = pushBack;
	da->is_empty = isEmpty;
	da->clear = Clear;
	da->remove_at = removeAt;

	// alloc memory of size capacity 
	da->data = malloc(sizeof(void*) * da->capacity);
	//da->data = malloc(da->capacity);

}


