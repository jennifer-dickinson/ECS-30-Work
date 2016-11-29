//
//  make_binary_points.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 11/21/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_vals = 3; // Num user numbers

    
    printf("\nEnter number of points: ");
    scanf(" %d", &num_vals);
    
    FILE* outFile = NULL;     // File pointer
    int userNums[num_vals][2]; // User numbers
    int i = 0;                // Loop index
    
    // Get numbers from user
    printf("\nEnter %d points...\n", num_vals);
    for (i = 0; i < (num_vals); ++i) {
        printf("%d: ", i+1);
        scanf("%d %d", &(userNums[i][0]), &(userNums[i][1]));
    }
    
    // Try to open the file
    outFile = fopen("myfile.bin", "wb+");
    if( outFile == NULL ) {
        printf("Could not open file myfile.bin.\n");
        return -1; // -1 indicates error
    }
    
    // Write user values to output file
    printf("Writing numbers to myfile.bin.\n");
    fwrite(&num_vals, sizeof(int), 1, outFile);
    
    for (i = 0; i < num_vals; ++i) {
        fwrite(&(userNums[i][0]), sizeof(int), 1, outFile);
        fwrite(&(userNums[i][1]), sizeof(int), 1, outFile);
    }
    
    rewind(outFile);
    int value1, value2;
    
    fread(&num_vals, sizeof(int), 1, outFile);
    printf ("Number of points: %d\n", num_vals);

    for (i = 0; i < num_vals; i++) {
        fread(&value1, sizeof(int), 1, outFile);
        fread(&value2, sizeof(int), 1, outFile);

        printf("Point %d: %d %d\n", i+1, value1,value2);
    }
    
    // Done with file, so close it
    printf("Closing file myfile.bin.\n");
    fclose(outFile);
    
    return 0;
}
