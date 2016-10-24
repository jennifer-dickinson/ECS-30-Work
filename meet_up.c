//
//  meet_up.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 10/23/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int assert_formatting(int numberOfArguments, int numNeeded) {
    // read the entire line if user input and check if it is valid.
    char newLine;
    int garbage = 0;
    do {
        scanf("%c", &newLine);
        garbage = (newLine != '\n' && newLine != ' ') || garbage;
    } while (newLine != '\n');
    return (numberOfArguments == numNeeded && !garbage);
}

int UserPrompt(int *seed, int *rows, int *columns, int *rounds) {
    int numOfArgs = 0;
    do {
        printf("Enter the seed for the random number generator: ");
        numOfArgs = scanf(" %i", &*seed);
    } while (!assert_formatting(numOfArgs, 1));

    do {
        printf("Enter the number of rows on the board: ");
        numOfArgs = scanf(" %i", &*rows);
    } while (!assert_formatting(numOfArgs, 1) || *rows < 1);

    do {
        printf("Enter the number of columns on the board: ");
        numOfArgs = scanf(" %i", &*columns);
    } while (!assert_formatting(numOfArgs, 1) || *columns < 1);

    do {
        printf("Enter the number of simulations to run: ");
        numOfArgs = scanf(" %i", &*rounds);
    } while (!assert_formatting(numOfArgs, 1) || *rounds < 1);

    return 0;
}

int move(int self, int other) {
    return rand() % abs(self - other) + (self < other ? self : other);
}

int RunSimulation(int rows, int columns, int rounds) {
    // Generate starting positions;
    int P1_R, P1_C, P2_R, P2_C;

    int P1_R_OLD, P1_C_OLD, P2_R_OLD, P2_C_OLD, totalrounds = 0;
    
    
    for (int i = 0; i < rounds; i++) {
        P1_R = rand() % rows;
        P1_C = rand() % columns;
        P2_R = rand() % rows;
        P2_C = rand() % columns;

        if (rounds < 5) {
            printf("\nSimulation %d\n", i);
            printf("Piece one starts at: %d, %d\n", P1_R, P1_C);
            printf("Piece two starts at: %d, %d\n", P2_R, P2_C);
        }
        while (1) {
            
            if (P1_R == P2_R && P1_C == P2_C) break;
            totalrounds++;
            
            P1_R_OLD = P1_R;
            P2_R_OLD = P2_R;
            P1_C_OLD = P1_C;
            P2_C_OLD = P2_C;
            
            if (P1_R != P2_R) P1_R = move(P1_R, P2_R);
            if (P1_C != P2_C) P1_C = move(P1_C, P2_C);
            if (P1_R != P2_R) P2_R = move(P2_R, P1_R);
            if (P1_C != P2_C) P2_C = move(P2_C, P1_C);

            if (rounds < 5) {
                printf("First piece moves from %d,%d to %d,%d\n", P1_R_OLD, P1_C_OLD, P1_R, P1_C);
                printf("Second piece moves from %d,%d to %d,%d\n", P2_R_OLD, P2_C_OLD, P2_R, P2_C);
            }
        }
    }
    
    printf("\nOn average it takes %.2lf rounds on a board %d X %d for the pieces to meet.\n",
           (totalrounds / (float) rounds), rows, columns);
    return 0;
}

int main() {
    int seed, rows, columns, rounds;

    UserPrompt(&seed, &rows, &columns, &rounds);

    srand(seed);

    RunSimulation(rows, columns, rounds);


    return 0;

}
