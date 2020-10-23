#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main (int argc, char *argv[]) {
    int i;

    printf("入力された文字列数は%d個です。\n", argc);
    for(i = 0; argv[i] != NULL; i++){
        printf("文字列%d：%s\n", i + 1, argv[i]);
    }
    return 0;
}