//
//  bin_str.c
//  ECS 30 Work
//
// This program will take a string of binary numbers as a parameter, with missing numbers marked as an 'x' and output all possible combinations of binary numbers with x's replaced as either 1's or 0's.
//
//  Created by Jennifer Salas on 11/26/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bin_strings (char str[]);
void _bin_strings (char str2[], char str1[], unsigned long length);

int main( int argc, char** argv) {
    // Accept user input and run bin_string
    
    bin_strings(argv[1]);
    return 0;
}


void bin_strings (char str[]) {
    // Take a binary string and run _bin_strings to fill missing numbers.

    // Get length of inputted string
    unsigned long str_len = strlen(str);
    
    // Create placeholder for temporary string
    char temp[str_len];
    strcpy(temp, "");
    
    // Begin recursive function
    _bin_strings (str, temp, str_len) ;
}


void _bin_strings (char str2[], char str1[], unsigned long length) {
    
    // Get the length of str2
    int str2_len = (int)strlen(str2);
    
    int index = 0;
    
    while(index < str2_len) {
        // Search for an 'x' in str2
        
        if (str2[index] == 'x') {
            
            // Append up to and including the 'x' to str1
            strncat(str1, str2, index+1);
            int x_pos = (int)strlen(str1) - 1;
            
            // Copy str1 and replace 'x' with '0'
            char temp1[length];
            strcpy(temp1, str1);
            temp1[x_pos] = '0';
            
            // Run recursive for str1 with '0'
            _bin_strings (str2+index+1, temp1, length);
            
            
            // Copy str1 and replace 'x' with '1'
            char temp2[length];
            strcpy(temp2, str1);
            temp2[x_pos] = '1';
            
            // Run recursive for str1 with '1'
            _bin_strings (str2+index+1, temp2, length);
            
            // Break loop to avoid printing unnecessary information
            break;
        }
        index++;
    }
    
    if (index == str2_len) {
        // If no 'x' found in while loop, combine strings and print
        strcat(str1, str2);
        printf("%s\n", str1);
    }
    
}
