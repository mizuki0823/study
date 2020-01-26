#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
    int a[16];
    unsigned short x;
    int k = 0;

    printf("入力：");
    scanf("%hu",&x);
    while( x > 0 ){
        a[k] = x & 1;
        x >>= 1;
        k ++;
    }
    if (k == 0)
        printf("0");
    for (int i = k-1; i >= 0; i --)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}