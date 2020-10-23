#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char moji_1, moji_2, *m1_pt, *m2_pt;

    m1_pt = &moji_1;
    m2_pt = &moji_2;

    printf("変数moji_1のアドレスは%pです。\n", m1_pt);
    printf("変数moji_2のアドレスは%pです。\n", m2_pt);
    return 0;
}