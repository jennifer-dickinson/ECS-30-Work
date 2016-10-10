//
//  complex_mult.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 9/26/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//
//  This program takes two complex numbers in the form of ai + b and multiples them together.

#include <stdio.h>

int main() {
    // main will accept complex numbers inputted by the user, perform a binomial multiplaction, and print out the result.
    
    // Variables defined by the user
    int complex1, real1, complex2, real2, multComplex, multReal;
    
    // Accept the first complex number, ignore any whitespace
    printf("Enter the first complex number in the form ai + b: ");
    scanf(" %d i + %d", &complex1, &real1);
    //printf("You entered %di + %d\n", complex1, real1);
    
    // Accept the second complex number, ignore any whitespace
    printf("Enter the second complex number in the form ai + b: ");
    scanf(" %d i + %d", &complex2, &real2);
    //printf("You entered %di + %d\n", complex2, real2);
    
    // Perform complex number multiplication
    // (a1 * i + b1) (a2 * i + b2)
    // = (a1 * i * a2 * i) + (a1 * i * b2)+ (b1 * a2 * i) + (b1 * b2)
    // = -(a1 * a2) + (a1 * bw + b1 * a2) i + (b1 * b2)
    // = (a1 * b2 + b1 * a2) i + (b1 * b2 - a1 * a2)
    
    multComplex = complex1 * real2 + real1 * complex2;
    multReal = real1 * real2 - complex1 * complex2;
    
    printf("(%di + %d) * (%di + %d) = %di + %d\n", complex1, real1, complex2, real2,
           multComplex, multReal);
    
    return 0;
    
}
