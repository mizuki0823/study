#include <stdio.h>
typedef int ABC;
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    ABC a = 5;

    printf("a = %d\n", a);

    return 0;
}