//
//  pi.c
//  ECS 30 Work
//
//  pi.c will generate a given amount of points in a 2x2 box. Points that land within a distance of 1 unit will be calculated as inside of a circle and used to estimate the value of pi.
//
//  Created by Jennifer Salas on 10/23/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int assert_formatting(int numberOfArguments, int numNeeded) {
    // read the entire line if user input and check if it is valid.
    char newLine;
    int garbage = 0;
    do {scanf("%c", &newLine);
        garbage = (newLine != '\n' && newLine !=' ') || garbage;
    } while ( newLine != '\n');
    return (numberOfArguments == numNeeded && !garbage);
}

float RandomNumber() {
    // Generate  random number in [-1, 1].
    const double LO = -1.0;
    const double HI = 1.0;
    return LO + ((double) (rand()) /(((double) RAND_MAX)/(HI-LO)));
}

void UserPrompt (int *seed, int *iterations) {
    // Get seed and iteration times  from user input.
    int numberOfArguments;
    do {
        printf("Enter the seed for the random number generator: ");
        numberOfArguments = scanf(" %i", &*seed);
    } while ( !assert_formatting(numberOfArguments, 1));
    
    do {
        printf("Enter the number of iterations to run: ");
        numberOfArguments = scanf(" %i", &*iterations);
    } while ( !assert_formatting(numberOfArguments, 1) || *iterations < 1);
    
}

void CalculatePi (int seed, int iterations) {
    // Use the  Monte Carlo method to estimate pi.
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

int main() {
    int seed = 0, iterations = 0;
    UserPrompt(&seed, &iterations);
    srand(seed);
    CalculatePi(seed, iterations);

}
