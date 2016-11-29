//
//  heist.c
//  ECS 30 Work
//
//  This program will add items of a certain weight and value into a bag until the bag is full and print out the most profitable value.
//
//  Created by Jennifer Salas on 11/27/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    // New data type with attributes of value and weigh to represent items
    int value;
    int weight;
} item;

void _knapsack ( item* items, int num_items, int max_items, int max_weight, int high_val, int *highest_val) {
    
 
    if (max_weight < 0) {
        // The bag is over capacity, end the recursinon
        return;
    }
    
    else if (high_val > *highest_val) {
        // If the value of the bag is higher than the highest stored value, update highest_val to new value
        *highest_val = high_val;
    }
    
    for (int i = 0; i < num_items; i++) {
        // The recursion occurs here
        
        _knapsack(items + i + 1, num_items - (i + 1), max_items, max_weight - items[i].weight, high_val + items[i].value, highest_val);
        // param 1 - move pointer the (i + 1) position
        // param 2 - decrease num items by (i + 1)
        // param 3 - max items remains the same
        // param 4 - decrease total carrying capacity
        // param 5 - increase value of load
        // param 6 - pass highest value pointer for recursion
        
    }
}

double Knapsack(int num_items, item* items, int max_weight) {
    // items: the array of struct elements
    // num_items: number of elements in the array
    // max_weight: maximum weight the bag can hold
    // highest_val: the current value of
    
    int highest_val = 0;
    _knapsack(items, num_items, num_items, max_weight, highest_val, &highest_val);
    
    return highest_val;
}

void User_Prompt() {
    // Prompt user for maximum carrying capacity, number of available items and the weight and value of each item.
    double max_weight;
    unsigned int num_items;
    
    printf("Enter the maximum amount of weight that your bag can hold: ");
    scanf(" %lf", &max_weight);
    
    printf("Enter the number of items that are in the jewelry store: ");
    scanf(" %d", &num_items);
    
    item* items = (item*)malloc(sizeof(item) * (num_items));
    
    printf("Enter your items, one per line (value weight):\n");
    for (int i = 0; i < num_items; i++) {
        scanf(" %d %d", &items[i].value, &items[i].weight);
    }
    
    // Calculate the highest profit from the combination of items with limitations on weight.
    int profit = Knapsack(num_items, items, max_weight);

    printf("They most profitable heist will net you $%d in total.\n", profit);
    
    
}



int main () {
    
    User_Prompt();
    
    return 0;
}
