//
//  anagram.c
//  ECS 30 Work
//
//  anagram.c will check whether two strings are anagrams
//
//  Created by Jennifer Salas on 10/31/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ReorderString(char string[]) {
    // Reorder a string from lowest to highest ascii character
    char swap;

    for (int i = 0; i < strlen(string); i++) {
        for (int j = i; j < strlen(string); j++) {
            if (string[i] > string[j]) {
                swap = string[i];
                string[i] = string[j];
                string[j] = swap;
            }
        }
    }
}

void checkAnagram(char word1[], char word2[]) {

    // Make copies of the strings
    char temp1[20] = "";
    strcpy(temp1, word1);

    char temp2[20] = "";
    strcpy(temp2, word2);

    if (strlen(word1) == strlen(word2)) {

        // Change all to upper case
        for (int i = 0; i < strlen(temp1); i++) {
            temp1[i] = toupper(temp1[i]);
            temp2[i] = toupper(temp2[i]);
        }

        ReorderString(temp1);
        ReorderString(temp2);

        if (strcmp(temp1, temp2) == 0) {
            printf("%s is an anagram of %s\n", word1, word2);
            return;
        }
    }
    printf("%s is NOT an anagram of %s\n", word1, word2);
}


void UserPrompt() {
    // Ask user for two words to compare
    char word1[20], word2[20];
    printf("Please enter the first word: ");
    scanf(" %s", word1);

    printf("Please enter the second word: ");
    scanf(" %s", word2);

    checkAnagram(word1, word2);
}

int main() {
    UserPrompt();
    return 0;
}
