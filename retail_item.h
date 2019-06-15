#ifndef RETAIL_ITEM_H
#define RETAIL_ITEM_H

#define MAX_NAME_LENGTH 16

/* define retail_item struct below */
typedef struct retail_item
{
int number;
char name[MAX_NAME_LENGTH+1];
int price_cents;
}
retail_item;

/* function prototypes -- should match your .c implementation */
retail_item create_retail_item (int num, char *name, int price);
void print(retail_item ri);

#endif
