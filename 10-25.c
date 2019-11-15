//int main(void) {    void：引数、　int:戻り値の型、　処理内容：　０を返す
//    return 0;

//}
#include <stdio.h>
// int kasan(int, int);
// double josan(int, int);
int kasan(int x, int y)
{
    int z;
    z = x +y;
    return z;
}

double josan(int a, int b)
{
    return (a / b);
}
int main(void)
{
    int     a = 10, b = 3, wa;
    double  shou;

    wa = kasan(a, b);
    shou = josan(a, b);

    printf("%dと%dの和は%d,商は%.1fです\n", a, b, wa, shou);
    return 0;
}

