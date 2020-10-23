#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char *m_pt;
    int i;

    m_pt = "lucky!";
    for(i = 0; m_pt[i] != '\0'; i++)
        printf("配列の%d番目の要素は%cです。\n", i + 1, m_pt[i]);
    return 0;
}