#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int fibo(int);
int main () {
    int n;
    printf("入力してください\n");
    scanf("%d",&n);
    printf("%d\n", fibo(n));
    return 0;
}

int fibo(int x){
   if(x <= 2)
   return 1;

   else{
     return fibo(x - 1) + fibo(x - 2);
   } 
}