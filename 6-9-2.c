#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    int suuchi[5] = {10, 20, 30, 40, 50};
    int *s_pt, i;

    s_pt = suuchi;
    for(i = 0; i < 5; i++)
        printf("要素%dは%dです。\n", i + 1, *(s_pt + i));
    return 0;
}