//
//  quad.c
//  ECS 30 Work
//
//  This program will take a quadratic equation and find its zeros, if any exist.
//
//  Created by Jennifer Salas on 10/9/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main () {
    double a, b, c, descriminant, solution1, solution2;
    
    
    // Prompt user for quadratric formula values
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    
    printf("Please enter a: ");
    scanf(" %lf", &a);
    
    printf("Please enter b: ");
    scanf(" %lf", &b);

    
    printf("Please enter c: ");
    scanf(" %lf", &c);

    
    // Perform calculation
    
    // Check if real by checking discriminant
    descriminant = pow (b, 2) - 4*a*c;
    
    if (descriminant < 0) {
        printf ("There are no real solutions\n");
    }
    else if (descriminant == 0) {
        solution1 = ( - b ) / ( 2 * a);
        printf("There is one real solution: %.2lf\n", solution1);
    }
    else {
        solution1 = ( -b + sqrt(descriminant)) / ( 2 * a);
        solution2 = ( -b - sqrt(descriminant)) / ( 2 * a);

        printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf\n", solution1, solution2);
    }
    
}
