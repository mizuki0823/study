#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int nazo(int);
int main () {
    int n;
    printf("入力してください\n");
    scanf("%d",&n);
    printf("%d\n", nazo(n));
    return 0;
}

int nazo(int x){
   if(x > 0 && x < 4)
   return x;

   else{
       printf("整数値");
       scanf("%d", &x);
     return nazo( x );
   } 
}