#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
    char c;
    int n;

    printf("入力");
    n = 0;
    while ( ( c = getchar() ) != '\n'){
        n *= 8;
        n += c - '0';
    }
    printf("出力 %d\n", n);
    
    return 0;
}