//
//  foo.c
//  ECS 30 Work
//
//  Created by Jennifer Salas on 11/21/16.
//  Copyright © 2016 Jennifer Salas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int foo(int n);
int _foo (int n1, int n2, int n3, int n4);

int main (int argc, char **argv) {
    
    int n = atoi(argv[1]);
    
    printf ("foo(%d) = %d\n", n, foo(n));
    
    return 0;
}


int foo( int n) {
    return _foo (n, 2, 3, 5);
}

int _foo (int n, int n1, int n2, int n3) {
    if (n == 0) {
        return n1;
    }
    else if (n == 1) {
        return n2;
    }
    else if (n == 2) {
        return n3;
    }
    else {
        return _foo (n-1, n2, n3, n1 + n2 + n3);
    }
}
