#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char c;
    int n, k;

    printf("入力：");

    n = 0; k = 0;
    while (( c = getchar() ) != '\n'){
        n *= 10;
        n += c - '0';
        k++;
    }

    printf("出力：%d（桁数 = %d）\n", n, k);
    return 0;


}