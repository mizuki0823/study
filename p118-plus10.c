#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

void bin(int);
int main () {
    int n;
    printf("入力");
    scanf("%d", &n);
    bin(n);
    printf("\n");
    return 0;
}

void bin (int x) {
    if( x < 2) {

        printf("%d",x);
        return;
    }
    else    
    {
        bin(x / 2);
        printf("%d", x % 2);
       
    
    }
}