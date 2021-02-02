#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

#include "stack.h"
#include "stackf.c"


int main () {
    MyStack *s= allocS(3);
    //push test
    printS(s);
    pushS(s,1);
    printS(s);
    pushS(s, 2);
    printS(s);

    //pop test
    printf("pop: %d\n", 1);
    popS(s);
    printS(s);
    
    return 0;
}