//
//  investments.c
//  ECS 30 Work
//
//  This program will calculate whether it is better to make full or minimum payments on a loan with the remaining going to an investment account. investments.c makes use of do while loops and pointers as an exercise. A modified and more compact version of assert_formatting has been implemented.
//
//  Created by Jennifer Salas on 10/16/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool assert_formatting(int numberOfArguments, int numNeeded) {
    // read the entire line if user input and check if it is valid.
    
    char newLine;
    bool garbage = false;
    do {scanf("%c", &newLine);
        garbage = (newLine != '\n' && !isspace(newLine)) || garbage;
        } while ( newLine != '\n');
    return (numberOfArguments == numNeeded && !garbage);
}

// For use in SingleInputValidation to check input
enum dataType {
    DOUBLE, INTEGER
};

void SingleInputValidation(char string[], enum dataType type, void *value) {
    // SingleInputValidation will print a message and request input until a valid input is entered and then return the value to a variable
    int numberOfArguments = 0;
    bool greaterThanZero = false;

    do {
        printf("%s", string);
        if (type == INTEGER) {
            numberOfArguments = scanf(" %d", &*(int *) value);
            greaterThanZero = *(int *) value > 0;
        }
        else {
            numberOfArguments = scanf(" %lf", &*(double *) value);
            greaterThanZero = *(double *) value > 0.0;
        }
    } while (!(assert_formatting(numberOfArguments, 1) && greaterThanZero));


}

void LoanAndSavingsCalc(double loanPrin, double MPR, double moPay, double loanPay, double MRR, int mosToRetire, double *finSavBal, double *finLoanBal) {
    // loanAndSavingsCalc() will calculate the total accured savings and final loan amount after a given period of time based on the payment applied to each.
    double interest, investmentPayment = moPay - loanPay, loanBal = loanPrin, savBal, savInt;

    while (mosToRetire > 0) {
        // Calculate loan balance
        interest = loanBal * MPR;
        loanBal += interest;

        // Calculate loan payment
        if (loanBal > loanPay && loanPay > 0) {
            loanBal -= loanPay;
        }
        else if (loanBal > 0) {
            loanPay = loanBal;
            loanBal = 0;
            investmentPayment = moPay - loanPay;
        }
        else {
            investmentPayment = moPay;
        }

        // Calculate accured return
        savInt = savBal * MRR;
        savBal += investmentPayment + savInt;
        --mosToRetire;
    }
    *finLoanBal = loanBal;
    *finSavBal = savBal;
}

void UserPrompt() {
    double moPay, loanPrin, APR, minMoPay, ARR, MPR, MRR, minPaySavBal, minPayLoanBal, maxPaySavBal, maxPayLoanBal;
    int age, retAge, mosToRetire;

    SingleInputValidation("Enter how much money you will be putting towards loans/retirement each month: ",
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
    } while (retAge <= age);
    mosToRetire = (retAge - age) * 12;

    SingleInputValidation("Enter the annual rate of return you predict for your investments: ",
                          DOUBLE, &ARR);
    MRR = ARR / 12.0;

    // Check how much investment will be accrued if the minimum is payed to loan
    LoanAndSavingsCalc(loanPrin, MPR, moPay, minMoPay, MRR, mosToRetire, &minPaySavBal, &minPayLoanBal);

    // Check how much investment will be accrued if the max amount of money is payed to laon
    LoanAndSavingsCalc(loanPrin, MPR, moPay, moPay, MRR, mosToRetire, &maxPaySavBal, &maxPayLoanBal);

    // Check which is better;
    bool minPayTrue = (minPaySavBal > maxPaySavBal &&
                       (minPaySavBal != maxPaySavBal || !(minPayLoanBal > maxPayLoanBal)));
    double loanBal = (minPayTrue) ? minPayLoanBal : maxPayLoanBal;

    // Print out the better of the either paying minimum payments to loan or paying the max amount available.
    printf("Min loan balance: $%.2lf and Max loan bal: $%.21lf\n", minPayLoanBal, maxPayLoanBal);
    if (loanBal > 0) {
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", loanBal);
    }
    if (minPayTrue) {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");

        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.\n",
               minPaySavBal, maxPaySavBal);
    }
    else {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", moPay);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n",
               maxPaySavBal, minPaySavBal);
    }
}

int main() {
    UserPrompt();
    return 0;
}
