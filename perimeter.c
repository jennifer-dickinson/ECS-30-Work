//
//  perimeter.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 11/21/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void read_lines(FILE *fp, char ***lines, int *num_lines);
FILE* validate_input(int argc, char* argv[]);
int **get_points (FILE* fp, int *num_points);
double calculate_perimiter(int **points, int num_points);
double calculate_distance (int x1, int y1, int x2, int y2);

int main (int argc, char * argv[]) {
    
    FILE* fp = validate_input(argc, argv);
    
    int num_points = 0;
    int **points = get_points(fp, &num_points);
    
    double perimiter = calculate_perimiter(points, num_points);
    
    printf("The perimeter is %.2lf\n", perimiter);
    
    return 0;
}

FILE* validate_input(int argc, char* argv[]){
    
    FILE* fp = NULL;
    
    if(argc < 2){
        printf("Not enough arguments entered.\nEnding program.\n");
        exit(0);
    }
    else if(argc > 2){
        printf("Too many arguments entered.\nEnding program.\n");
        exit(0);
    }
    
    fp = fopen(argv[1], "rb");
    
    if(fp == NULL){
        printf("Unable to open file: %s\nEnding program.\n", argv[1]);
        exit(0);
    }
    
    return fp;
    
}

int **get_points (FILE* fp, int *num_points) {
    int numPoints = 0, i = 0;
    
    fread(&numPoints, sizeof(int), 1, fp);
    
//    printf("Number of points: %d\n", numPoints);
    
    int **nums = (int**)malloc( numPoints * sizeof(int*));
    
    for ( i = 0; i < numPoints; i++) {
        nums[i] = (int*)malloc( 2 * sizeof(int));
        fread(&nums[i][0], sizeof(int), 1, fp);
        fread(&nums[i][1], sizeof(int), 1, fp);
        
//        printf("Point %d: %d %d \n", i, nums[i][0], nums[i][1]);

    }
    
    *num_points = numPoints;
    return nums;
}

double calculate_perimiter(int **points, int num_points) {
    double distance = 0.0;
    for ( int i = 0; i < num_points - 1; i++) {
        distance += calculate_distance(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
    }
    distance += calculate_distance(points[num_points-1][0], points[num_points-1][1], points[0][0], points[0][1]);
    
    return distance;
}

double calculate_distance (int x1, int y1, int x2, int y2) {
    double distance = 0.0;
    
    distance = sqrt( pow(x1 - x2, 2) + pow (y1 - y2, 2));
    
//    printf("The distance betwee %d %d, and %d %d: %.2lf\n", x1, y1, x2, y2, distance);
    
    return distance;
}

