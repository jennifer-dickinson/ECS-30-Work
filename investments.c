//
//  investments.c
//  ECS 30 Work
//
//  This program will calculate whether it is better to make full payments on a loan or minimum payments on a loan with the remaining going to an investment account.
//
//  Created by Jennifer Salas on 10/16/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void UserPrompt();

bool assert_formatting (int numberOfArguments, int numNeeded) {
    // Checks if user input is formatted correctly.
    char garbage[1];
    scanf("%[^\n]", garbage);
    if (numberOfArguments == numNeeded && strlen(garbage) == 0) {
        return true;
    }
    return false;
}

// For use in SingleNumValid to check input
enum dataType {DOUBLE, INTEGER};

void SingleInputValidation (char string[80], enum dataType type, void* value) {
    // This function will print a message and request input until a valid input is entered and then return the value to a variable
    int numberOfArguments = 0;
    bool greaterThanZero = false;
    
    do {
        printf("%s", string);
        if (type == INTEGER) {
            numberOfArguments = scanf(" %d", &*(int*)value);
            greaterThanZero = *(int*)value > 0;
        }
        else {
            numberOfArguments = scanf(" %lf", &*(double*)value);
            greaterThanZero = *(double*)value > 0.0;
        }
        
    } while ( !assert_formatting(numberOfArguments, 1) || !greaterThanZero);
    void free(void* value);
}

void loanAndSavingsCalc( double loanPrin, double MPR, double moPay, double loanPay, double MRR, int mosToRetire, double* finSavBal, double* finLoanBal) {
    // loanAndSavingsCalc will calculate the total accured savings and final loan amount after a given period of time based on the payment applied to each.
    double interest = 0.0, investmentPayment = moPay - loanPay, loanBal = loanPrin, savBal = 0, savInt = 0.0;
    while (mosToRetire > 0) {
        interest = loanBal * MPR;
        loanBal += interest;
        
        // Calculate loan payment
        if (loanBal > loanPay && loanPay > 0) {
            loanBal -= loanPay;
        }
        else if ( loanBal > 0) {
            loanPay = loanBal;
            loanBal = 0;
            investmentPayment = moPay - loanPay;
        }
        else {
            investmentPayment = moPay;
        }
        
        savInt = savBal * MRR;
        savBal += investmentPayment + savInt;
        --mosToRetire;
    }
    *finLoanBal = loanBal;
    *finSavBal = savBal;
}

void UserPrompt() {
    double moPay, loanPrin, APR, minMoPay, ARR, MPR, MRR,  minPaySavBal, minPayLoanBal, maxPaySavBal, maxPayLoanBal;
    int age = 0, retAge = 0, mosToRetire = 0;
    
    SingleInputValidation("Enter how much money you will be putting towards loans/retirement each \
                          month: ",
                          DOUBLE, &moPay);
    
    SingleInputValidation("Enter how much you owe in loans: ",
                          DOUBLE, &loanPrin);
    
    SingleInputValidation("Enter the annual interest rate of the loans: ",
                          DOUBLE, &APR);
    MPR = APR / 12.0;
    
    SingleInputValidation("Enter your minimum monthly loan payment: ",
                          DOUBLE, &minMoPay);
    
    // First check if enough money is set aside to pay minimum
    if (minMoPay > moPay) {
        printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
        exit(0);
    }
    
    SingleInputValidation("Enter your current age: ", INTEGER, &age);
    
    // Couldn't avoid making a do while loop here.
    do {
        SingleInputValidation("Enter the age you plan to retire at: ",
                              INTEGER, &retAge);
    } while ( retAge <= age);
    mosToRetire = (retAge - age) * 12;
    
    SingleInputValidation("Enter the annual rate of return you predict for your investments: ",
                          DOUBLE, &ARR);
    MRR = ARR /12.0;
    
    // Check how much investment will be accrued if the minimum is payed to loan
    loanAndSavingsCalc(loanPrin, MPR, moPay, minMoPay, MRR, mosToRetire, &minPaySavBal, &minPayLoanBal);
    
    // Check how much investment will be accrued if the max amount of money is payed to laon
    loanAndSavingsCalc(loanPrin, MPR, moPay, moPay, MRR, mosToRetire, &maxPaySavBal, &maxPayLoanBal);
    
    // Check which is better;
    bool minPayTrue = (minPaySavBal > maxPaySavBal && !(minPaySavBal == maxPaySavBal && (minPayLoanBal > maxPayLoanBal)));
    double loanBal = (minPayTrue)? minPayLoanBal: maxPayLoanBal;
    double savBal = (minPayTrue)? minPaySavBal : maxPaySavBal;
    double lesSavBal = (minPayTrue)? maxPaySavBal: minPaySavBal;

    if ( loanBal > 0 ) {
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", loanBal);
        }
    if (minPayTrue) {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
    }
    else {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", moPay);
    }
    printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.\n", savBal, lesSavBal);
    
}

int main () {
    UserPrompt();
}
