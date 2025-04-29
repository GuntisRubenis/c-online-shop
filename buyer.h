#ifndef BUYER_H
#define BUYER_H

#define NAME_SIZE 30


typedef struct buyer{

    char name[NAME_SIZE +1];
    struct buyer *next_buyer;
    struct cart *grocery_items_bought;
    float total_cost;
} buyer;

void add_buyer(struct buyer **buyers);
void see_buyers(struct buyer *buyers);


#endif
