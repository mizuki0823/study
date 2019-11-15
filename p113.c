#include <stdio.h>
void shuukei (int);
int  soukei = 0;//グローバル変数
int main(void)
{
    int in_d;

    printf("整数値を入力してください（終了はCTL＋D）：");
    while(scanf("%d", &in_d) != EOF)
    {
        shuukei(in_d);       //関数の呼び出し
        printf("整数値を入力してください（終了はCTL＋D）：");

    }
    printf("\n集計結果：%dです\n", soukei);
    return 0;
}

void shuukei(int x)
{
    soukei += x;
}
