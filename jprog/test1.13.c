#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

#define m 10

int main () {
    int d[m];

    printf("%p\n", &d[m]);
    printf("%p\n", d + m);

    return 0;
}