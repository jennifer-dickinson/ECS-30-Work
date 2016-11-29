//
//  tail.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 11/21/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

void read_lines(FILE *fp, char ***lines, int *num_lines);
FILE* validate_input(int argc, char* argv[]);
void print_lines (char **lines, int num_lines, int print_num);

int main (int argc, char * argv[]) {
    
    FILE* fp = validate_input(argc, argv);
    
    char **lines = NULL;
    int num_lines = 0;
    
    read_lines(fp, &lines, &num_lines);
    print_lines(lines, num_lines, atoi(argv[2]));
    
    
    return 0;
}

FILE* validate_input(int argc, char* argv[]){
    
    FILE* fp = NULL;
    
    if(argc < 3){
        printf("Not enough arguments entered.\nEnding program.\n");
        exit(0);
    }
    else if(argc > 3){
        printf("Too many arguments entered.\nEnding program.\n");
        exit(0);
    }
    
    fp = fopen(argv[1], "r");
    
    if(fp == NULL){
        printf("Unable to open file: %s\nEnding program.\n", argv[1]);
        exit(0);
    }
    
    return fp;
    
}

void read_lines(FILE *fp, char ***lines, int *num_lines) {
    
    char **lines_read = (char**)malloc(sizeof(char*));
    int total_lines = 0;
    
    *num_lines = 0;
    
    while(!feof(fp)) {
        total_lines += 1;
        lines_read = (char**)realloc(lines_read, ( (total_lines) * sizeof(char*)));
        lines_read[total_lines-1] = (char*)malloc( 100 * sizeof(char));
        fgets(lines_read[total_lines-1], 100, fp);
        
    }
    
    *lines = lines_read;
    *num_lines = total_lines -1 ;
}

void print_lines (char **lines, int num_lines, int print_num) {
    
    for (int i = (print_num >= num_lines)? 0 : num_lines - print_num; i < num_lines; i++) {
        printf("%s", lines[i]);
    }
}
