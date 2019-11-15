#include <stdio.h>
#include <math.h>
void j_heikin(int);
float goukei = 0;
float kosu = 0;
int main(void)
{
    int a;

     printf("整数値を入力してください（終了はCTL＋D）：");
    while(scanf("%d", &a) != EOF)
    {
        printf("整数値を入力してください（終了はCTL＋D）：");
        j_heikin(a);       //関数の呼び出し
    }
    printf("\n結果：%.0fです\n", goukei / kosu);
    return 0;
}

void j_heikin(int x) {
    goukei += x;
    kosu ++;
}