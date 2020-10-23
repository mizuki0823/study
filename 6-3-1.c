#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    double s_data[4] = {17, 24, 38, 45};
    double *s_pt;

    s_pt = s_data;

    printf("配列の1番目のアドレスは%p、配列の1番目の要素は%dです。\n",s_data, *s_pt);
    printf("配列の2番目のアドレスは%p、配列の2番目の要素は%dです。\n",(s_data + 1), *(s_pt +1));
    printf("配列の3番目のアドレスは%p、配列の2番目の要素は%dです。\n",(s_data + 2), *(s_pt +2));
    printf("配列の4番目のアドレスは%p、配列の2番目の要素は%dです。\n",(s_data + 3), *(s_pt +3));
    return 0;
}