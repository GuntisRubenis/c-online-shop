#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MENU_SIZE 20
#define NAME_SIZE 30
//#define NAME_FORMAT "%" #NAME_SIZE "s"


struct {
    
    char *oper_name;

} menu [] = {

    {"add_buyer"},
};

typedef struct grocery_items {

    char item_name[NAME_SIZE +1];
    float price;
    int stock;
    struct grocery_items *next_item;

} grocery_items;

struct cart {

    struct grocery_items *items_bought;
    struct cart *next_item;
};

typedef struct buyer{

    char name[NAME_SIZE +1];
    struct buyer *next_buyer;
    struct cart *grocery_items_bought;
    float total_cost;
} buyer;

void add_buyer(struct buyer **buyer);

int main(){
    
    int menu_len = sizeof(menu) / sizeof(menu[0]);
    char selected_oper[MENU_SIZE+1];
    bool oper_found = true;
    struct buyer *all_buyers = NULL;

    printf("Welcome to Wallmart!\n");
    
    for (;;){
        printf("\nOperations: \n");

        for (int i = 0; i < menu_len; i++ ){
            
            printf("%d. %s\n", i+1 , menu[i].oper_name);
        }

        printf("\nSelect operation (type exit to quit): ");
        scanf("%20s", selected_oper);

        if (strcmp(selected_oper, "exit") == 0){
            printf("Leaving store, gobye...\n");
            return 0;
        }

        for(int i = 0; i < menu_len; i++){

            
                if (strcmp("add_buyer", menu[i].oper_name) == 0) {
                   oper_found = true;
                   add_buyer(&all_buyers);
                   break;
                }

            oper_found = false;
        }

        if (oper_found == false){
            printf("\nOpertion was not found try aggain...\n");
        }
    }


}

void add_buyer(struct buyer **buyer){

    printf("\nAdding new buyer..\n");
    struct buyer *new_buyer;
    new_buyer = malloc(sizeof(struct buyer));

    if (new_buyer == NULL){

       printf("\nError in malloc add_buyer..\n");
       exit(EXIT_FAILURE);
    }

    printf("Enter buyers name: ");
    scanf("%s", new_buyer->name);
    new_buyer->total_cost = 0.0f;
    new_buyer->grocery_items_bought = NULL;
    new_buyer->next_buyer = *buyer;
    *buyer = new_buyer;
    getchar();
    printf("\nNew buyer added succesfully!\n");
}


