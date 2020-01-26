#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)
#define NEW     18
#define OTONA    "大人料金です\n"
#define KODOMO  "子供料金です\n"


int main () {
    int nenrei;

    printf("入場者の年齢を入力:");
    scanf("%d", &nenrei);

    if(nenrei >= NEW)
        printf(OTONA);
    else
        printf(KODOMO);
    return 0;
}