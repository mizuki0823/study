#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)
#define meiji(a)  (a - 1867)
#define taisyo(a) (a - 1911)
#define syouwa(a) (a - 1925)
#define heysay(a) (a - 1988)
#define reiwa(a) (a - 2018)

int main () {
    int n;

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
    return 0;
}