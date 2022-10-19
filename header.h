// header.h
#include <stdio.h>
/*

Abhi Vachani
Project 2 - Header File
Computer Systems Organization
Prof. Kayar


Dynamic Array: 
• allocates memory dynamically (i.e. adds and removes objects dynamically)
• has random access to stored elements

Dynamic Array struct which holds
o pointer to an array of generic data type
o initial capacity of the array
o actual count of currently existing items
o function pointers to all necessary functions: isEmpty, pushBack, removeAt, clear.


*/




typedef struct {
	// data - array
	void **data;

	// capacity and count - ints
	int capacity;
	int count;


	// function pointers
	void (*push_back)(struct DynamicArray*, void*);
	
	int (*is_empty)(struct DynamicArray*, void*);

	void (*clear)(struct DynamicArray*, void*);

	void (*remove_at)(struct DynamicArray*, int i);




} DynamicArray;


// init pointer
void init(DynamicArray* DynAr);