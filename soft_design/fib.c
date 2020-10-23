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

    for(int i=1; i<n; i++){
        printf("%d項の値は%dです\n", i, fib(i));
    }
   
    printf("1~%d項までのフィボナッチ数の総和は%dです\n", n, fib(n));

    return 0;
}

int fib(int x){

    if(x < 1){
        return 0;
    }
    else if(0<=x && x<=1){
        return (x);
    }
    else{
        return fib(x-2) + fib(x-1);
    }
}