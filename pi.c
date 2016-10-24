//
//  pi.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 10/23/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
// enables use of rand()

#include <stdlib.h>

// for use with assert_formatting
#include <stdbool.h>
#include <ctype.h>

// for pow and sqrt
#include <math.h>

bool assert_formatting(int numberOfArguments, int numNeeded) {
    // read the entire line if user input and check if it is valid.
    
    char newLine;
    bool garbage = false;
    do {scanf("%c", &newLine);
        garbage = (newLine != '\n' && !isspace(newLine)) || garbage;
    } while ( newLine != '\n');
    return (numberOfArguments == numNeeded && !garbage);
}

float RandomNumber() {
    const double LO = -1.0;
    const double HI = 1.0;
    return LO + ((double) (rand()) /(((double) RAND_MAX)/(HI-LO)));
}

int main() {
    int numberOfArguments = 0, seed = 0, iterations = 0;
    
    do {
        printf("Enter the seed for the random number generator: ");
        numberOfArguments = scanf(" %i", &seed);
    } while ( !assert_formatting(numberOfArguments, 1));

    do {
        printf("Enter the number of iterations to run: ");
        numberOfArguments = scanf(" %i", &iterations);
    } while ( !assert_formatting(numberOfArguments, 1) || iterations < 1);
    
    srand(seed);
    float x,y, length;
    int inCircle = 0;
    for ( int i = 0; i < iterations; i++) {
        x = RandomNumber();
        y = RandomNumber();
        length = sqrt( pow (x, 2) + pow (y, 2));

        if ( length <= 1) {
            inCircle++;
        }
    }
    
    float probability = (float)inCircle / (float)iterations;
    float pi = probability * 4;
    printf("The value of pi is %.5lf.\n", pi);
}
