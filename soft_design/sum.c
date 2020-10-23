#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int sum(int x);

int main () {
    int n;

    printf("数を入力:");
    scanf("%d", &n);

    printf("1~%d総和は%dです\n", n, sum(n));

    return 0;
}

int sum(int x){

    if(x < 1){
        return 0;
    }
    else{
        return ( x + sum(x-1) );

    }
}