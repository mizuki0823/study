#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)
#define URINE(x) (x) * 1.05

int main () {
    int motone;

    printf("商品の原価を入力:");
    scanf("%d", &motone);

    if(motone <= 1000)
        /*通常商品*/
        printf("売値:%.0f円\n", URINE(motone));
    else
        /*値引商品*/
        printf("売値:%.0f円\n", URINE(motone - 300));    
    return 0;
}