#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int shuukei(int *, int);

int main () {
    int ten[10] = {60,45,82,49,91,52,77,39,100,73};
    int h_suu = 10;

    printf("要素の合計は%dです。\n", shuukei(ten, h_suu));
    return 0;
}

int shuukei(int * ten_pt, int youso_suu){
    int i, goukei = 0;

    for(i = 0; i < youso_suu; i++)
        goukei += ten_pt[i];
    return goukei;
}