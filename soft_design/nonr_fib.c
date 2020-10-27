#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int fib(int x);

int main () {
    int n;

    printf("数を入力:");
    scanf("%d", &n);


        printf("%d項の値は%dです\n",n, fib(n));

    return 0;
}

int fib(int x){

    int x1=0,x2=1,result=0;

    if(x < 1){
        return 0;
    }
    else if(0<=x && x<=1){
        return (x);
    }
    else{
        for(int i=2; i<=x; i++){
            result = x1 + x2;
            x1 = x2;
            x2 = result;
        }
        return result;
    }
}