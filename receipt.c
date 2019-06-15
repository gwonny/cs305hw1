// CS 305, SPRING 2018
// HOMEWORK 1

// receipt.c
// author: Johnny Huang

// defines the actions of structure receipt, which notable quality includes
// having an array of retail_item and being able to print out the
// item number, name, and price.

// a brief overview of the functions found in receipt.c is in receipt.h

// mainly written in notepad++, but compiled and ran on mobaxterm

#include "receipt.h" //includes header files
#include "retail_item.h"
#include <stdio.h> //includes standard io and standard libraries
#include <stdlib.h> 


receipt* create_receipt(int max_it)//same as prototype in header, pointer is used as return so manipulation of data on struct can be achieved
{
	receipt* receiptp; //pointer to receipt
	receiptp = (receipt*)malloc(sizeof(receipt));//mallocs receipt-worth of memory and casts to pointer
	(*receiptp).num_items=0; //sets num_items to 0 thru pointer
	if(max_it>0)
	{
		(*receiptp).max_items=max_it; //if max_items positive, set it to max_items
		(*receiptp).items=(retail_item*)malloc(max_it*sizeof(retail_item));//mallocs retail_item-worth of memory (times max item allowed given) and casts it to retail_item pointer in receipt pointer
	}
	else
	{
		(*receiptp).max_items=20; //if negative or other scenario, change to default 20
		(*receiptp).items=(retail_item*)malloc(20*sizeof(retail_item)); //similar to previous malloc but times default max size of 20
	}
	return receiptp;//returns pointer
}


int add_item(receipt* rec, retail_item item)//adds a retail_item into receipt
{
	if((*rec).num_items>=(*rec).max_items)//accesses num_items value of dereferenced receipt pointer
	{
		printf("Cannot add another item to receipt. Maximum size has been reached.\n\n");//if the receipt is equal to or has more items than it allows, will no longer accept anymore
		return -1;
	}
	else
	{
		(*rec).items[(*rec).num_items]=item;//earliest empty space gets filled up with item
		(*rec).num_items=(*rec).num_items+1;//number of items raised by one as a result
		return 0;
	}
}

int delete_item(receipt* rec, int item_num)//deletes a given item, identified by item number
{
	int i = 0;//will be used in for-loops
	int j = 0;
	if((*rec).num_items<=0)//if the receipt is empty or (for some reason) negative
	{
		printf("Item number %d not found. Did not delete.\n\n", item_num);//prints deletion failure
		return -1;
	}
	for(i;i<(*rec).num_items;i++)
	{
		if((*rec).items[i].number==item_num)//otherwise, runs thru the entire item array's numbers to see if it matches given item number for deletion
		{
			j = i;//if passes, position is recorded onto j
			for(j;j<(*rec).num_items;j++)//...where it is the start of another for-loop...
			{
			(*rec).items[j]=(*rec).items[j+1];//in order to overwrite the data to-be-deleted and move every data after it back 1...
			}
			(*rec).num_items=(*rec).num_items-1;//and finally decreases size of receipt so previous last-data is inaccessible
			
			return 0;
		}
		else
		{
			if(i==(*rec).num_items-1)//if scans thru entire array, and no success in finding item number in receipt
			{
				printf("Item number %d not found. Did not delete.\n", item_num);//prints deletion failure
				return -1;
			}
		}
	}
}


void print_receipt(receipt* rec)
{
	int i = 0;
	int tcost = 0;//holds total cost of receipt that's compounded with for-loop
	printf("Receipt:\n");
	for(i;i<(*rec).num_items;i++)//for-loop
	{
		printf("Item %d\t %s\t $%.02f\n", (*rec).items[i].number, (*rec).items[i].name, (double)((*rec).items[i].price_cents)/(double)100);//prints item number, name, and price (after casting it when it's divided by a casted value of 100)
		tcost = tcost + (*rec).items[i].price_cents;//compounds price each item scanned
	}
	printf("Total: $%.02f\n\n", (double)((tcost)/(double)100));//prints total price found from tcost, calculated and casted another time
}

void free_receipt(receipt* rec)//frees memory that's been mallocd
{
	free(rec);
}
