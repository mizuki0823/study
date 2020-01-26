#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)


float f(int, int);
float p = 0;

int main () {
    int n1, n2 = 1;
    float w;
    while (1){
        printf("入力");
        if(scanf("%d",&n1) == EOF)
            break;
        w = f(n1,n2);
        n2 ++;
    }
    printf("\n出力 %.1f\n", w);
    return 0;
}

float f(int x, int n){
    p += x;

    return p / n;
}