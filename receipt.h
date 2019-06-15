#ifndef RECEIPT_H
#define RECEIPT_H

#include "retail_item.h"

/* define receipt struct below */
typedef struct receipt //structure defined in header and typedefd to allow common-use of its name in other files
{
retail_item* items; //array of retail items
int num_items; //number of items receipt will have at a given time
int max_items; //max number of items the receipt may carry
}
receipt; 

/* function prototypes - should match your .c implementations */
receipt* create_receipt(int max_it);
int add_item(receipt * rec, retail_item item);
int delete_item(receipt * rec, int item_num);
void print_receipt(receipt * rec);
void free_receipt(receipt * rec);

#endif
