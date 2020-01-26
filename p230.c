#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)
#define FALSE 0

int main () {
    printf("EOF = %d\n", EOF);
    printf("FALSE = %d\n", FALSE);

    return 0;
}