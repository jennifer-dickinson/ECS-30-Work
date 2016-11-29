//
//  read_lines.h
//  ECS 30 Work
//
//  Created by Jennifer Salas on 11/14/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#ifndef read_lines_h
#define read_lines_h

#include <stdio.h>

void read_lines(FILE* fp, char*** lines, int* num_lines);
char* read_line(FILE *fp);

#endif /* read_lines_h */
