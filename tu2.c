#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
    char a[9];
    unsigned short x;
    int k = 0;

    printf("入力：");
    scanf("%hu",&x);

     while( x > 0 ){
        x >>= 1;
        a[k] |= x;
        a[k] += '0';
        printf("%c\n", a[k]);
        // x >>= 1;
        k ++;
    }
    /*for(int i = 0; strlen(a) / 2; i++){


    }
    printf("%s\n", a);*/
    return 0;
}