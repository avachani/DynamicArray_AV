//main.c

#include <stdio.h>
#include <stdlib.h>
#include "header.h"


/*

Abhi Vachani
Project 2 - Main File
Computer Systems Organization
Prof. Kayar

*/


int main (int argc, char** args) 
{

	// Initialize DynamicArray
	DynamicArray da;
	init(&da);


	// Print initial values of count and capacity
	printf("Initialization - count: %d, capacity: %d\n\n", da.count, da.capacity);

	// push all values in the array
	pushBack(&da, "Abhi");
	pushBack(&da, "NYU");
	pushBack(&da, "CSCI");
	pushBack(&da, "201");
	pushBack(&da, "Fall");
	pushBack(&da, "2022");
	pushBack(&da, "Project201");


	
	// step 2 - count total elements in array and capacity 
	printf("Step 2 - count: %d, capacity: %d\n", da.count, da.capacity);


	// print values in array
	int i;
	for (i = 0; i < da.count; i++)
	{
		printf("%s\n", (char*)da.data[i]);
	}



	// remove element at index 2
	removeAt(&da, 2);

	// step 3 - count elements in array and capacity 
	printf("\nStep 3 - count: %d, capacity: %d\n\n", da.count, da.capacity);


	// print elements in array after removal
	printf("Dynamic Array data: \n\n");
	int j;
	for (j = 0; j < da.count; j++)
	{
		printf("%s\n", (char*)da.data[j]);
	}

	// clear array
	Clear(&da);



	// check if array is empty now and print 
	if(isEmpty(&da) == 1)
		printf("\nThe array is empty now\n");


	// return 0 - program runs correctly
	return 0;


}
