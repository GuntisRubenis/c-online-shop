#include "buyer.h"
#include <stdio.h>
#include <stdlib.h>

void add_buyer(struct buyer **buyers){

    printf("\nAdding new buyer..\n");
    struct buyer *new_buyer;
    new_buyer = malloc(sizeof(struct buyer));

    if (new_buyer == NULL){

       printf("\nError in malloc add_buyer..\n");
       exit(EXIT_FAILURE);
    }

    printf("Enter buyers name: ");
    scanf("%30s", new_buyer->name);
    new_buyer->total_cost = 0.0f;
    new_buyer->grocery_items_bought = NULL;
    new_buyer->next_buyer = *buyers;
    *buyers = new_buyer;
    getchar();
    printf("\nNew buyer added succesfully!\n");
}


void see_buyers(struct buyer *buyers){
    int counter = 1;

    printf("\n%s\n","Name");
    for (;buyers != NULL; buyers = buyers->next_buyer){

        printf("%d. %s\n",counter++, buyers->name);
    }
}

