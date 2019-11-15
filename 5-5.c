#include<stdio.h>
#include<string.h>

int main(void)
{
    int i, j;
    int kingaku[50];
    char shouhin[50][10];
    char work[10];
    int kingaku_work;

    // 入力
    for ( i = 0; i < 50; i ++ ) {
        printf("商品コード  金額... ");
        if ( scanf("%s%d", shouhin[i], &kingaku[i]) == EOF ) {
            break;
        }
    }
    // ↓その他変数定義　５−５全く手付かずだから５−４の３倍わからないんだ
    int N = i; //←このNって何者？　おっけー プツッてる　これで完成してる感じ？
    // ここ、iだけでOKでした(たぶん)えっと、最後に合計金額を表示しなきゃいけなかったはず
    // とりあえずこれ(N=i)で動くかやってみよう
    // あとで何か入れます(文字列に意味はない) ごめんなんて？

    // データの選びかた
    for ( i = 0; i < N - 1; i ++ ) {
        // ここじゃないヨ
        for ( j = i + 1; j < N; j ++ ) {
            // データの入れ替えをここでやる
            // もし、＊＊＊＊＊(教科書p158?それですだったら
            // ↓ 多分ok
            // ここ間違ってました shouhin[i],shouhin[i] になってた　あー
            //                                    ↑
            if(strcmp(shouhin[i],shouhin[j]) > 0 ) {// 文字”列"は<, >で比較できないので、関数を使う

                //shouhin i,jの交換
                // これ、↓ここでshouhin[i], shouhin[j]が同じになったあとに、!
                strcpy(work, shouhin[i] );
                // ここで代入しているので、2つとも同じになってしまう
                strcpy(shouhin[i], shouhin[j]);
                // だから、一度shouhin[j]をworkに退避して、i←j、j←workとしないといけない
                strcpy(shouhin[j], work);

                // workは複数保持する必要はないから２次元配列じゃないので、関数でwork自体にコピーしよう
            

            // shouhin[i] と kingaku[i]は2つに一つなので、それぞれで比べるのではなく、
            // 今回は商品名順なので、商品名を入れ替えることになったら同時に、金額も同じように入れ替える
            

                //kingaku i,jの交換
                kingaku_work = kingaku[i];
                kingaku[i] = kingaku[j];
                kingaku[j] = kingaku_work;
                // ここも↑と同じなんかこいつバカ正直に順番に表示してない？
            }
        
            
        }
    }
    // 最後に合計金額を表示すれば終わりです
    // なにか変数を用意して、
    int m;
    m = 0;
    // 勝手に追加した
    printf("\n売り上げ明細\n");
    for(i = 0; i < N; i ++){
        // 出力したあとに用意した変数に足しましょう
        printf("%s %d\n", shouhin[i], kingaku[i]);
        m = m + kingaku[i]; 

    }
    // 足した変数を出力しましょう
    printf("\n合計金額は%d\n", m);
    // 寝る おやすみ 

    return 0;
}

    