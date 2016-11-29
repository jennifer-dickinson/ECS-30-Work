//
//  read_lines.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 11/14/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdlib.h>
#include "read_lines.h"

void read_lines(FILE *fp, char ***lines, int *num_lines) {
    
    char **lines_read = (char**)malloc(sizeof(char*));
    int total_lines = 0;

    *num_lines = 0;
    
    while(!feof(fp)) {
        total_lines += 1;
        lines_read = (char**)realloc(lines_read, ( (total_lines) * sizeof(char*)));
        lines_read[total_lines-1] = (char*)malloc( 60 * sizeof(char));
        fgets(lines_read[total_lines-1], 60, fp);
        
    }
    
    *lines = lines_read;
    *num_lines = total_lines -1 ;
}
