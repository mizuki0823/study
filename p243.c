#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)
#define DT1 10
#define DT2 4
#define KEISAN1(x) (x) * 2
#define KEISAN2(y) (y) / 2
#define KEISAN3(x, y) (x) / (y)

int main () {
    int x, y;
    int k1, k2, k3;

    x = DT1;
    y = DT2;
    printf("x = %d y = %d\n", x, y);
    k1 = KEISAN1(y);
    k2 = KEISAN2(x);
    k3 = KEISAN3(KEISAN1(x), KEISAN2(y));

    printf("k1 = %d k2 = %d k3 = %d\n", k1, k2, k3);
    return 0;
}