//
//  dist.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 9/28/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <math.h>


int main() {
    
    // user defined variables
    double x1, y1, x2, y2;
    
    // calculated variables
    double distance;
    
    printf("Enter the first point in the form x,y: ");
    scanf(" %lf , %lf", &x1, &y1);
    
    printf("Enter the second point in the form x,y: ");
    scanf(" %lf , %lf", &x2, &y2);
    
    distance = sqrt( pow(x1 - x2, 2) + pow( y2 - y1, 2));
    
    printf("The distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.2lf.\n", x1, y1, x2, y2, distance);
    
    
    
    
    return 0;
}
