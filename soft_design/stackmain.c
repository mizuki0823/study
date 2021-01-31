#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

#include "stack.h"


int main () {
    MyStack *s= allocS(3);
    printS(s);
    pushS(s,1);
    printS(s);
    pushS(s);
    
    return 0;
}