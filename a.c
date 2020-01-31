#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

void f(int);

int main () {
    int n;

    printf("入力： ");
    scanf("%d", &n);
    printf("出力：\n");
    f(n);
    return 0;
}

void f(int x){
    int i;

    if(x < 1)
        return;

    for(i = 0; i < x; i ++)
        printf("+ ");
    printf("\n");
    f(x - 1);
    for(i = 0; i < x; i ++)
        printf("* ");
    printf("\n");
}