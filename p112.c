#include <stdio.h>
int jijyou(int);
int souwa = 0;
int main(void)
{
    int a = 2, b = 5, wa, i;
    for (wa = i = 0; i < 3; i++)
        wa += jijyou(a + i);
    printf("一回目の出力：%d\n", wa);
    for (wa = 0, i = 4; i >= 1; i--)
        wa += jijyou(b - i);
    printf("二回目の出力%d\n", wa);
    printf("三回目の出力%d\n", souwa);
    return 0;
}
int jijyou(int a)
{
    int wa;
    wa = a * a;
    souwa += wa;
    return wa;
}