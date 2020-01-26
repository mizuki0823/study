#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pm8.h"

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
     int n;
     float a, b;

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


    printf("西暦を入力 ");
    scanf("%d", &n);

    if(n < 1900){
        printf("%d年は明治より前です\n", n);
    }

    else if(n <= 1911){
        printf("%d年は明治%d年です\n", n, meiji(n));
    }

    else if(n <= 1925){
         printf("%d年は大正%d年です\n", n, taisyo(n));
    }

    else if(n <=1988){
         printf("%d年は昭和%d年です\n", n, syouwa(n));
    }

    else if(n < 2019){
         printf("%d年は平成%d年です\n", n, heysay(n));
    }

    else if(n == 2019){
         printf("%d年は平成%d年です\n", n, heysay(n));
         printf("%d年は令和%d年です\n", n, reiwa(n));
    }

    else{
        printf("%d年は令和%d年です\n", n, reiwa(n));
    }

    printf("２つの整数値を入力 ");
    scanf("%f%f", &a, &b);

    printf("%.0f\n", max(a,b));
    return 0;
}