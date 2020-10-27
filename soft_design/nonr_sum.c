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

    int k=0,result=0;

    if(x < 1){
        printf("%d %d\n",k,result);
        return 0;
    }
    else{
        for(int i=0; i<x; i++){
            k=x-i;
            result = result + k;
        }
        return result;
    }

}