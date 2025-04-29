#include "items.h"
#include <stdio.h>
#include <stdlib.h>

void add_item(struct grocery_items **items){
    printf("\nAdding new item..\n"); 
    
    struct grocery_items *new_item;
    new_item = malloc(sizeof(struct grocery_items));
    
    if (new_item == NULL){
        printf("Error in malloc add_item");
        exit(EXIT_FAILURE);
    }

    printf("Enter item name: ");
    scanf("%s", new_item->item_name);
    getchar();

    printf("Enter item price: ");
    scanf("%f", &new_item->price);

    printf("Enter item quantity: ");
    scanf("%d", &new_item->stock);

    new_item->next_item = *items;
    *items = new_item;

    printf("\nNew item added succesfully..\n");
}


void see_items(struct grocery_items *items){
    int counter = 1;
    printf("Available items:\n");
    printf("\n%-5s %-30s %-5s %-5s\n","Nr.", "Name", "Price", "Quantity");
    for (;items != NULL; items = items->next_item){

        printf("%-5d %-30s %-5.2f %-5d\n",counter++, items->item_name, items->price, items->stock);
    }
}
