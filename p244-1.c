#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)
#define ka  60
#define ryo 70
#define yu  80

int main () {
    int n;

    printf("点数の入力 ");
    scanf("%d", &n);

    if(n < ka){
        printf("不可\n");
    }

    else if(n < ryo){
        printf("可\n");
    }

    else if(n < yu){
        printf("良\n");
    }
    
    else
        printf("優\n");

    return 0;
}