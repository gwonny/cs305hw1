// CS 305, SPRING 2018
// HOMEWORK 1

// retail_item.c
// author: Johnny Huang

// defines the structure retail_item, which is put as an array in structure receipt 
// and contains the item number, name, and price in cents

// a brief overview of the functions found in retail_item.c is in retail_item.h

// mainly written in notepad++, but compiled and ran on mobaxterm

#include "retail_item.h"
#include "receipt.h"
#include <stdio.h>

retail_item create_retail_item(int num, char* name, int price)
{
	retail_item item; //declared retail_item object
	if(num>0)
	{
		item.number = num; //set item number to number given
	}
	else
	{
		printf("Negative item number detected. Changing item number to default of 9999.\n");
		item.number = 9999; //if given number is negative, set to default of 9999
	}
	if(price>0)
	{
		item.price_cents = price; //same scenario for price of retail_item
	}	
	else
	{
		printf("Negative price detected. Changing item price to default of 0.\n");
		item.price_cents = 0; //default price if given price was a negative number
	}
	int i = 0;
		while(name[i]!='\0')//if position of string is not null...
		{
		item.name[i]=name[i];//copy it
		i++;
		}
		for(i;i<MAX_NAME_LENGTH;i++)
		{
			item.name[i]=' ';//starts off at where while-loop left to replace the rest with whitespace
		}
	item.name[MAX_NAME_LENGTH]='\0';//adds a null at the very end position
	return item;//returns item with all info established
}
void print(retail_item ri)//not used, but same result done another way
{
}