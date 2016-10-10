//
//  conversions.c
//  ECS 30 Work
//
//  This program will allow a user to convert distance or temperature in different units of measurement.
//
//  Created by Jennifer Salas on 10/9/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double convertTemperature(char unit, char newUnit, double number) {
    // Convert a given temperature to another (fahrenheit, celsius, and Kelvin)
    if ( unit == newUnit) {
        return number;
    }
    else if (unit == 'F') {
        // Convert fahrenheit to celsius or Kelvin
        switch (newUnit) {
            case 'C':
                return (number - 32) * 5/9;
            case 'K':
                return (number - 32) * 5/9 + 273.15;
        }
    }
    else if (unit == 'C') {
        // Convert celsius to fahrenheit or Kelvin
        switch (newUnit) {
            case 'F':
                return (number * 9/5) + 32;
            case 'K':
                return number + 273.15;
        }
    }
    else if (unit == 'K') {
        // Convert Kelvin to celsius or fahrenheit
        switch (newUnit) {
            case 'C':
                return (number - 273.15);
            case 'F':
                return (number - 273.15) * 9/5 + 32;
        }
    }
    // Should never get to this point because of input validation
    return  9999.99;
}

void checkTemperatureUnit (char unit[20]) {
    // Check to see if the user inputed a valid temperature unit of Kelvin, celsius or fahrenheit
    unit[0] = toupper(unit[0]);
    if (strlen(unit) != 1) {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
    
    else if(! (unit[0] == 'K' || unit[0] == 'C' || unit[0] == 'F') ) {
        printf("%s is not a valid temperature type. Ending program.\n", unit);
        exit(0);
    }
}

void temperatureConversionPrompt () {
    // Prompt user for the temperature and initial unit and the unit to convert it to.
    double number;
    char unit[20], newUnit[20];
    
    printf("Enter the temperature followed by its suffix (F, C, or K): ");
    scanf(" %lf %s", &number, unit);
    checkTemperatureUnit(unit);
    unit[0] = toupper(unit[0]);
    
    printf("Enter the new unit type (F, C, or K): ");
    scanf(" %s", newUnit);
    checkTemperatureUnit(newUnit);
    newUnit[0] = toupper(newUnit[0]);
    
    printf("%.2lf%s is %.2lf%s\n", number, unit, convertTemperature(unit[0], newUnit[0], number), newUnit);
    
}

double convertDistance ( char unit, char newUnit, double number) {
    // Convert a distance from one unit to another (inches, feet, yards, and meters)
    if (unit == newUnit) {
        return number;
    }
    else if ( unit == 'I') {
        // Convert inches to feet, yards or meters
        switch (newUnit) {
            case 'F':
                return number / 12.0;
            case 'Y':
                return number / 36.0;
            case 'M':
                return number / 63360.0;
                
        }
    }
    else if ( unit == 'F') {
        // Convert feet to inches, yards or meters
        switch (newUnit) {
            case 'I':
                return number * 12.0;
            case 'Y':
                return number / 3.0;
            case 'M':
                return number / 5280.0;
        }
    }
    else if (unit == 'Y') {
        // Convert yards to inches, feet or meters
        switch (newUnit) {
            case 'I':
                return number * 36.0;
            case 'F':
                return number * 3.0;
            case 'M':
                return number  / 1760.0;
        }
    }
    else if ( unit == 'M') {
        // Convert meters to inches, feet, or yards
        switch (newUnit) {
            case 'I':
                return number * 63360.0;
            case 'F':
                return number * 5280.0;
            case 'Y':
                return number * 1760.0;
        }
    }
    // Should never get to this point because of input validation
    return 9999.99;
}

void checkDistanceUnit ( char unit[20]) {
    // Check to make user inputted a valid distance unit of inches, feet, yards or meters
    unit[0] = toupper(unit[0]);
    if (strlen(unit) != 1 ) {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
    else if(! (unit[0] == 'I' || unit[0] == 'F' || unit[0] == 'Y' || unit[0] == 'M') ) {
        printf("%s is not a valid distance type. Ending program.\n", unit);
        exit(0);
    }
}

void distanceConversionPrompt () {
    // Prompt user for the distance and initial unit and the unit to convert it to.
    double number;
    char unit[20], newUnit[20];
    
    printf("Enter the distance followed by its suffix (I,F,Y,M): ");
    scanf(" %lf %s", &number, unit);
    checkDistanceUnit(unit);
    unit[0] = toupper(unit[0]);
    
    printf("Enter the new unit type (I,F,Y,M): ");
    scanf(" %s", newUnit);
    checkDistanceUnit(newUnit);
    newUnit[0] = toupper(newUnit[0]);
    
    printf("%.2lf%s is %.2lf%s\n", number, unit, convertDistance(unit[0], newUnit[0], number), newUnit);
    
}


void conversion(char choice[50]) {
    // Check for valid user input
    if (strlen(choice) > 1) {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
    // Prompt the user for more information based on choice
    switch (choice[0]) {
            case 'T':
            case 't':
            temperatureConversionPrompt();
            break;
            case 'D':
            case 'd':
            distanceConversionPrompt();
            break;
        default:
            printf("Unknown conversion type %c chosen. Ending Program.\n", choice[0]);
            exit(0);
    }
}


int main () {
    char choice[50] = "";
    
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    scanf(" %s", choice);

    conversion(choice);
    
    return 0;
}
