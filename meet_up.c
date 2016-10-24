//
//  meet_up.c
//  ECS 30 Work
//
//  meet_up.c will move two pieces across a grid towards each other until they are on the same space and print out the movement and average number of rounds to reach each other across multiple simulations.
//
//  Created by Jennifer Salas on 10/23/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void UserPrompt(), Move(), RunSimulation();

int assert_formatting(int numberOfArguments, int numNeeded) {
    // Read the entire line if user input and check if it is valid.
    char newLine;
    int garbage = 0;
    do {
        scanf("%c", &newLine);
        garbage = (newLine != '\n' && newLine != ' ') || garbage;
    } while (newLine != '\n');
    return (numberOfArguments == numNeeded && !garbage);
}

void UserPrompt(int *seed, int *rows, int *columns, int *rounds) {
    // Get user imput for seed, rows, columns, and rounds
    int numOfArgs = 0;
    do {
        printf("Enter the seed for the random number generator: ");
        numOfArgs = scanf(" %d", &*seed);
    } while (!assert_formatting(numOfArgs, 1));

    do {
        printf("Enter the number of rows on the board: ");
        numOfArgs = scanf(" %d", &*rows);
    } while (!assert_formatting(numOfArgs, 1) || *rows < 1);

    do {
        printf("Enter the number of columns on the board: ");
        numOfArgs = scanf(" %d", &*columns);
    } while (!assert_formatting(numOfArgs, 1) || *columns < 1);

    do {
        printf("Enter the number of simulations to run: ");
        numOfArgs = scanf(" %d", &*rounds);
    } while (!assert_formatting(numOfArgs, 1) || *rounds < 1);

    return;
}

void Move(int *self, int other) {
    // Calculate a new position and update variable self
    int move = random() % (abs(*self - other) + 1);
    *self += (*self < other) ? move : -move;
}

void RunSimulation(int rows, int columns, int numOfSims) {
    // Generate a random start position for two pieces and have them move a random distance towards each other.
    int P1_R, P1_C, P2_R, P2_C, P1_R_OLD, P1_C_OLD, P2_R_OLD, P2_C_OLD, totalrounds = 0;

    for (int i = 0; i < numOfSims; i++) {
        // Iterate the simulation a total of numOfSims.
        
        // Generate random start positions.
        P1_R = random() % rows;
        P1_C = random() % columns;
        P2_R = random() % rows;
        P2_C = random() % columns;

        if (numOfSims <= 5) {
            printf("\nSimulation %d\n", i);
            printf("Piece one starts at: %d, %d\n", P1_R, P1_C);
            printf("Piece two starts at: %d, %d\n", P2_R, P2_C);
        }
        while (P1_R != P2_R || P1_C != P2_C) {
            // Move the pieces towards each other until they acquire the same space.

            // Piece 1: update position
            P1_R_OLD = P1_R;
            P1_C_OLD = P1_C;
            if (P1_R != P2_R) Move(&P1_R, P2_R);
            if (P1_C != P2_C) Move(&P1_C, P2_C);

            // Piece 2: update position
            P2_R_OLD = P2_R;
            P2_C_OLD = P2_C;
            if (P2_R != P1_R) Move(&P2_R, P1_R);
            if (P2_C != P1_C) Move(&P2_C, P1_C);

            if (numOfSims <= 5) {
                printf("First piece moves from %d,%d to %d,%d\n", P1_R_OLD, P1_C_OLD, P1_R, P1_C);
                printf("Second piece moves from %d,%d to %d,%d\n", P2_R_OLD, P2_C_OLD, P2_R, P2_C);
            }

            totalrounds++;
        }
    }

    printf("\nOn average it takes %.2lf rounds on a board %d X %d for the pieces to meet.\n",
           ((float) totalrounds / (float) numOfSims), rows, columns);
}

int main() {
    int seed, rows, columns, rounds;

    UserPrompt(&seed, &rows, &columns, &rounds);

    srandom(seed);

    RunSimulation(rows, columns, rounds);


    return 0;

}
