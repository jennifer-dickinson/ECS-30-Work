//
//  loan_cost.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 9/26/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//
//  This program will calculate the monthly payment on a loan and the cost to borrow it.


#include <stdio.h>
#include <math.h>

int main() {
    
    // Variables to be defined by user input.
    double loanAmount, annualInterestRate;
    int numberOfPayments;
    
    // Variables to be calculated.
    double monthlyPayment, monthlyInterestRate, totalPayment, costToBorrow;
    
    printf("Please enter the amount of money you borrowed: $");
    scanf(" %lf", &loanAmount);
    
    printf("Please enter the annual interest rate: ");
    scanf(" %lf", &annualInterestRate);
    
    printf("Please enter the number of payments to be made: ");
    scanf(" %d", &numberOfPayments);
    
    // Calculate the monthly interest rate by dividing the annual interest rate into 12 months.
    monthlyInterestRate = annualInterestRate / 12;
    
    // Calculate the monthly payment to pay off the loan in the desired amount of monthly payments.
    monthlyPayment = (monthlyInterestRate * loanAmount) / ( 1 - pow(( 1 + monthlyInterestRate), -numberOfPayments));
    
    // Calculate the total payments to be made over the course of the loan.
    totalPayment = monthlyPayment * numberOfPayments;
    
    
    // Calculate the cost associated with borrowing the loan.
    costToBorrow = totalPayment - loanAmount;
    
    // Print the results to the user.
    printf("A loan of $%.2lf with an annual interest of %.2lf payed off over %d months will have monthly payments of $%.2lf.\n", loanAmount, annualInterestRate, numberOfPayments, monthlyPayment);
    printf("In total you will pay $%.2f, making the cost of your loan $%.2f.\n", totalPayment, costToBorrow);
    
    return 0;
    
    
    
}