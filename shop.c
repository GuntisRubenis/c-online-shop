#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "buyer.h"
#include "items.h"

//#define NAME_FORMAT "%" #NAME_SIZE "s"


struct {
    
    char *oper_name;

} menu [] = {
    {"exit"},
    {"add_buyer"},
    {"see_buyers"},
    {"add_item"},
    {"see_items"},
};


struct cart {

    struct grocery_items *items_bought;
    struct cart *next_item;
};




int main(){
    
    int menu_len = sizeof(menu) / sizeof(menu[0]);
    //char selected_oper[MENU_SIZE+1];
    int operation = 0;
    struct buyer *all_buyers = NULL;
    struct grocery_items *all_items = NULL;

    printf("Welcome to Wallmart!\n");
    
    for (;;){
        printf("\nOperations: \n");

        for (int i = 0; i < menu_len; i++ ){
            
            printf("%d. %s\n", i , menu[i].oper_name);
        }

        printf("\nSelect operation (type exit to quit): ");
       // scanf("%20s", selected_oper);
        scanf("%d", &operation);
        printf("\n");
        switch(operation){
            case 0:
                printf("Leaving store, gobye...\n");
                return 0;
            case 1:
               add_buyer(&all_buyers);
               break;
            case 2:                             
               see_buyers(all_buyers);
               break;
            case 3:
               add_item(&all_items);
               break;
            case 4:
               see_items(all_items);
               break;
            default:
                printf("\nOpertion was not found try aggain...\n");

        }         
        

    }


}


