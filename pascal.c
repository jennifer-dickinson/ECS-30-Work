//
//  pascal.c
//  ECS 30 Work
//
//  pascal.c will display Pascal's Triangle up to a given row.
//
//  Created by Jennifer Salas on 10/31/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


void UserPrompt(int *numLevels) {
    // Request number of rows to show
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf(" %d", *&numLevels);
}

void populateTriangle(int numLevels) {
    // Print Pascal's Triangle

    int i = 0, j = 0;
    int temp1[numLevels];
    int temp2[numLevels];

    for (i = 1; i <= numLevels; i++) {
        // Generate the row

        for (j = 0; j < i; j++) {
            // Generate the columns

            if (j == 0 || i == 0 || j == i - 1) {
                temp1[j] = 1;
            }
            else {
                temp1[j] = temp2[j - 1] + temp2[j];
            }
            printf("%d ", temp1[j]);
        }
        printf("\n");
        for (j = 0; j < numLevels; j++) {
            temp2[j] = temp1[j];
        }
    }

}


int main() {
    int numLevels;

    UserPrompt(&numLevels);

    populateTriangle(numLevels);

    return 0;
}
