#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    float a, b;

    printf("２つの整数値を入力 ");
    scanf("%f%f", &a, &b);

    printf("%.0f\n", max(a,b));
    return 0;
}