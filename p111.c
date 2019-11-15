//変数のスコープ　（有効範囲）
//関数は main と kasan
//関数 main 内のローカル変数。。。 a, b, x
//関数 kasan 内のローカル変数。。。　a, b
//※a, bは関数 kasan の仮引数
#include <stdio.h>
void kasan(int, int);       //関数　kasan　のプロトタイプ宣言　

int x;      //グローバル変数　（どの関数からも使える）

int main(void)
{
    int a = 18, b = 31;
    int x = 20;
            //ローカル変数　（関数　main　内でしか使えない）

    kasan(a, b);        // a, b　は実引数、戻り値は使わない
    printf("%dと%dの和は%dです\n", a, b, x);        //ローカル変数を参照...xの値がそのまま出てくる
    return 0;
}

void kasan(int a, int b)            //戻り値の型、関数名、仮引数リスト
{
    x = a + b;                                      //グローバル変数に代入
    //return x; を戻り値とすると正しく表示できる
}
//同じ名前の変数がグローバル変数とローカル変数にあるとき、グローバル変数が優先される
//出力結果：18と31の和は20です