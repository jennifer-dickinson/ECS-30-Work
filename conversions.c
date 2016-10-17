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
#include <ctype.h>

void assert_formatting(int numberOfArguments, int argumentsNeeded ) {
    char newLine = ' ';
    scanf("%c", &newLine);
    if (numberOfArguments != argumentsNeeded || newLine != '\n') {
        printf("Invalid formatting. Ending program");
        exit(0);
        }
}

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
            default:
                break;
        }
    }
    else if (unit == 'C') {
        // Convert celsius to fahrenheit or Kelvin
        switch (newUnit) {
            case 'F':
                return (number * 9/5) + 32;
            case 'K':
                return number + 273.15;
            default:
                break;
        }
    }
    else if (unit == 'K') {
        // Convert Kelvin to celsius or fahrenheit
        switch (newUnit) {
            case 'C':
                return (number - 273.15);
            case 'F':
                return (number - 273.15) * 9/5 + 32;
            default:
                break;
        }
    }
    // Should never get to this point because of input validation
    return  9999.99;
}

void checkTemperatureUnit (char unit) {
    // Check to see if the user inputed a valid temperature unit of Kelvin, celsius or fahrenheit
    if(! (unit == 'K' || unit == 'C' || unit == 'F') ) {
        printf("%c is not a valid temperature type. Ending program.\n", unit);
        exit(0);
    }
}

void temperatureConversionPrompt () {
    // Prompt user for the temperature and initial unit and the unit to convert it to.
    double number = 0.0;
    char unit = ' ', newUnit = ' ';
    int numberOfArguments = 0;
    
    printf("Enter the temperature followed by its suffix (F, C, or K): ");
    numberOfArguments = scanf(" %lf %c", &number, &unit);
    assert_formatting(numberOfArguments, 2);
    unit = toupper(unit);
    checkTemperatureUnit(unit);
    
    printf("Enter the new unit type (F, C, or K): ");
    numberOfArguments = scanf(" %c", &newUnit);
    assert_formatting(numberOfArguments, 1);
    newUnit = toupper(newUnit);
    checkTemperatureUnit(newUnit);
    
    printf("%.2lf%c is %.2lf%c\n", number, unit, convertTemperature(unit, newUnit, number), newUnit);
    
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
            default:
                break;
                
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
            default:
                break;
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
            default:
                break;
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
            default:
                break;
        }
    }
    // Should never get to this point because of input validation
    return 9999.99;
}

void checkDistanceUnit ( char unit) {
    // Check to make user inputted a valid distance unit of inches, feet, yards or meters
    if(! (unit == 'I' || unit== 'F' || unit == 'Y' || unit == 'M') ) {
        printf("%c is not a valid distance type. Ending program.\n", unit);
        exit(0);
    }
}

void distanceConversionPrompt () {
    // Prompt user for the distance and initial unit and the unit to convert it to.
    double number = 0.0;
    char unit = ' ', newUnit = ' ';
    int numberOfArguments = 0;
    
    printf("Enter the distance followed by its suffix (I,F,Y,M): ");
    numberOfArguments = scanf(" %lf %c", &number, &unit);
    assert_formatting(numberOfArguments, 2);
    unit = toupper(unit);
    checkDistanceUnit(unit);
    
    printf("Enter the new unit type (I,F,Y,M): ");
    numberOfArguments = scanf(" %c", &newUnit);
    assert_formatting(numberOfArguments, 1);
    newUnit = toupper(newUnit);
    checkDistanceUnit(newUnit);
    
    printf("%.2lf%c is %.2lf%c\n", number, unit, convertDistance(unit, newUnit, number), newUnit);
}

void conversion(char choice) {
    // Prompt the user for more information based on choice
    switch (choice) {
            case 'T':
            case 't':
            temperatureConversionPrompt();
            break;
            case 'D':
            case 'd':
            distanceConversionPrompt();
            break;
        default:
            printf("Unknown conversion type %c chosen. Ending Program.\n", choice);
            exit(0);
    }
}

int main () {
    char choice = ' ';
    int numberOfArguments = 0;
    
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    
    numberOfArguments = scanf(" %c", &choice);
    assert_formatting(numberOfArguments, 1);
    
    conversion(choice);
    
    return 0;
}
