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

int assert_formatting(int numberOfArguments, int numNeeded) {
    // read the entire line if user input and check if it is valid.
    
    char newLine;
    int garbage = 0;
    do {scanf("%c", &newLine);
        garbage = (newLine != '\n' && newLine !=' ') || garbage;
        } while ( newLine != '\n');
    return (numberOfArguments == numNeeded && !garbage);
}

void LoanAndSavingsCalc(double loanPrin, double MPR, double moPay, double loanPay, double MRR, int mosToRetire, double *finSavBal, double *finLoanBal) {
    // loanAndSavingsCalc() will calculate the total accured savings and final loan amount after a given period of time based on the payment applied to each.
    double interest, investmentPayment = moPay - loanPay, loanBal = loanPrin, savBal = 0, savInt;

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
    int age, retAge, mosToRetire, numArgs;


    do { printf("Enter how much money you will be putting towards loans/retirement each month: ");
        numArgs = scanf(" %lf", &moPay);
    } while ( !assert_formatting(numArgs, 1) || moPay < 0);

    do{ printf("Enter how much you owe in loans: ");
        numArgs = scanf(" %lf", & loanPrin);
    } while (!assert_formatting(numArgs, 1) || loanPrin < 0);

    do{ printf("Enter the annual interest rate of the loans: ");
        numArgs = scanf(" %lf", &APR);
    } while (!assert_formatting(numArgs, 1) || APR < 0);
    MPR = APR / 12.0;

    do{ printf("Enter your minimum monthly loan payment: ");
        numArgs = scanf(" %lf", &minMoPay);
    } while (!assert_formatting(numArgs, 1) || minMoPay < 0);

    // First check if enough money is set aside to pay minimum
    if (minMoPay > moPay) {
        printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
        exit(0);
    }

    do{ printf("Enter your current age: ");
        numArgs = scanf(" %d", &age);
    } while (!assert_formatting(numArgs, 1) || age < 0);

    do{ printf("Enter the age you plan to retire at: ");
        numArgs = scanf(" %d", &retAge);
        
    } while ( !assert_formatting(numArgs, 1) || retAge <= age);
    mosToRetire = (retAge - age) * 12;

    do{ printf("Enter the annual rate of return you predict for your investments: ");
        numArgs = scanf(" %lf", &ARR);
    } while (!assert_formatting(numArgs, 1) || ARR < 0);
    MRR = ARR / 12.0;

    // Check how much investment will be accrued if the minimum is payed to loan
    LoanAndSavingsCalc(loanPrin, MPR, moPay, minMoPay, MRR, mosToRetire, &minPaySavBal, &minPayLoanBal);

    // Check how much investment will be accrued if the max amount of money is payed to laon
    LoanAndSavingsCalc(loanPrin, MPR, moPay, moPay, MRR, mosToRetire, &maxPaySavBal, &maxPayLoanBal);

    // Check which is better;
    int minPayTrue = (minPaySavBal > maxPaySavBal &&
                       (minPaySavBal != maxPaySavBal || !(minPayLoanBal > maxPayLoanBal)));
    double loanBal = (minPayTrue) ? minPayLoanBal : maxPayLoanBal;

    // Print out the better of the either paying minimum payments to loan or paying the max amount available.
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
