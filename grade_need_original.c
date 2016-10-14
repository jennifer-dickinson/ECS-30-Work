//
//  grade_need.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 10/09/2016.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//
//  This program will calculate the graded need on the final in order to achieve the desired grade.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void calculateGrade(char desiredGrade, double currentPercentage, double finalWeight) {
    // Variables used to calculate the finalGrade
    double desiredGradePercentage, currentPercentageWeight, actualGrade, percentNeeded, finalGrade = 0.0;
    
    // Calculate the weight of the user's current grade
    currentPercentageWeight = (100 - finalWeight);
    
    // Calculate the class grade without the final
    actualGrade = currentPercentageWeight * currentPercentage / 100;
    
    // Set the percentage for the desired grade
    switch (desiredGrade) {
        case 'A':
        case 'a':
            desiredGradePercentage = 90.0;
            break;
        case 'B':
        case 'b':
            desiredGradePercentage = 80.0;
            break;
        case 'C':
        case 'c':
            desiredGradePercentage = 70.0;
            break;
        case 'D':
        case 'd':
            desiredGradePercentage = 60.0;
            break;
        default:
            desiredGradePercentage = 0.0;
    }
    
    percentNeeded = desiredGradePercentage - actualGrade;
    
    // Calculate the grade needed on the final exam
    finalGrade =  percentNeeded / finalWeight * 100;

    // Print the percentage needed on the final.
    if (finalGrade > 100.00) {
        printf("You cannot get a %c in the class because you would need to score at least %.2lf%% on the final.\n", desiredGrade, finalGrade);
    }
    else if (finalGrade < 0.00) {
        printf("You cannot score low enough on the final to get a %c in the class.\n", desiredGrade);
    }
    else {
        printf("You need a grade of at least %.2f%% on the final to get a %c in the class.\n", finalGrade, desiredGrade);
    }
    
}

char isValidGrade(char grade[5]){
    // Make sure input is in the format of a single letter (A-F, excluding E)
    bool isOneChar = (strlen(grade) == 1)? true: false;
    bool isE = (grade[0] == 'e' || grade[0] == 'E')? true : false;
    bool isA_F = ((grade[0] >= 'A' && grade[0] <= 'F') || (grade[0] >= 'a' && grade[0] <= 'f'))? true : false;
    if (!isOneChar) {
        printf("Invalid formatting. ");
    }
    else if (!isA_F || isE) {
        printf("Unknown Grade Received: %s. ", grade);
    }
    if (!isOneChar || isE || !isA_F) {
        printf("Ending program.\n");
        exit(0);
    }
    
    return (grade[0]);
    
}

double isValidPercentage(char number[5]){
    // Make sure input is in the format of a real number
    
    double percent = 0.0;
    bool pointExists = false;
    
    // If the first character is '-', the number is negative.
    if ( number[0] == '-') {
        printf("The number you last entered should have been positive. Ending program.\n");
        exit(0);
    }
    
    // Check to make sure each character is a number or that only a single point exists.
    for ( int i = 0; i < strlen(number); i++) {
        if ( !isdigit(number[i]) ) {
            if ( number[i] == '.' && !pointExists) {
                pointExists = true;
                continue;
            }
            printf("Invalid formatting. Ending program.\n");
            exit(0);
        }
    }
    
    percent = atoi(number);
    return percent;
}

int main () {
     //main accepts user input required to calculate a final grade on an exam and printsit to the user. It returns zero if no errors have occured.
    
    // User defined variables
    char desiredGrade[5], currentPercentage[5], finalWeight[5] = "";
    
    // Valid variables
    char validDesiredGrade = ' ';
    double validCurrentPercentage, validFinalWeight = 0.0;
    

    printf("Enter the grade you want in the class: ");
    scanf(" %[^\n]%*c", desiredGrade);
    validDesiredGrade = isValidGrade(desiredGrade);
    
    printf("Enter your current percent in the class: ");
    scanf(" %[^\n]%*c", currentPercentage);
    validCurrentPercentage = isValidPercentage(currentPercentage);

    
    printf("Enter the weight of the final: ");
    scanf(" %[^\n]%*c", finalWeight);
    validFinalWeight = isValidPercentage(finalWeight);
    
    // Calculate the grade needed on the final
    calculateGrade(validDesiredGrade, validCurrentPercentage, validFinalWeight);
    
    
    
}
