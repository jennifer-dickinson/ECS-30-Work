//
//  mat_add.c
//  ECS 30 Work
//
//  mat_add.c will sum the values of two matrices.
//
//  Created by Jennifer Salas on 10/31/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>

void addMatrix(int r, int c, int matA[r][c], int matB[r][c]) {
    // Add two matrices
    int sum;
    printf("A + B =\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum = matA[i][j] + matB[i][j];
            printf("%d ", sum);
        }
        printf("\n");
    }
}

void getElements(int r, int c, int matrix[r][c]) {
    // Get user input for a multidimensional array
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %d", &matrix[i][j]);
        }
    }
}

void UserPrompt() {
    // Prompt user for input
    int rows, columns;
    printf("Please enter the number of rows: ");
    scanf(" %d", &rows);

    printf("Please enter the number of columns: ");
    scanf(" %d", &columns);

    int matA[rows][columns];
    int matB[rows][columns];

    printf("Enter Matrix A\n");
    getElements(rows, columns, matA);

    printf("Enter Matrix B\n");
    getElements(rows, columns, matB);

    addMatrix(rows, columns, matA, matB);


}

int main() {
    UserPrompt();
    return 0;
}
