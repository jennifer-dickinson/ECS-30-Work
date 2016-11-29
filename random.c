//
//  random.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 10/12/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//


#include <stdio.h>

void ComputeChange(int totCents, int* quartersChange, int* dimesChange, int* nickelsChange, int* penniesChange) {
    *quartersChange = totCents / 25;
    totCents = totCents % 25;
    *dimesChange = totCents / 10;
    totCents = totCents % 10;
    *nickelsChange = totCents / 5;
    totCents = totCents % 5;
    *penniesChange = totCents;
    return;
}

int main(void) {
    
    int totalCents = 67;    // Total amount of change needed
    int quartersChange = 0; // Number of quarters used for change
    int dimesChange    = 0; // Number of dimes used for change
    int nickelsChange  = 0; // Number of nickels used for change
    int penniesChange  = 0; // Number of pennies used for change
    
    ComputeChange(totalCents, &quartersChange, &dimesChange, &nickelsChange, &penniesChange); // FIXME Add four pointer arguments
    
    printf("Change for %d cents is:\n", totalCents);
    printf("  %d quarters\n", quartersChange);
    printf("  %d dimes\n", dimesChange);
    printf("  %d nickels\n", nickelsChange);
    printf("  %d pennies\n", penniesChange);
    
    return 0;
}
