#ifndef ITEMS_H
#define ITEMS_H
#define NAME_SIZE 30


typedef struct grocery_items {

    char item_name[NAME_SIZE +1];
    float price;
    int stock;
    struct grocery_items *next_item;

} grocery_items;

void add_item(struct grocery_items **items);
void see_items(struct grocery_items *items);



#endif 
