#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char a[30];

    while(1){
        printf("英文字列入力：");

        // ん、scanfではないのは何か理由が?なるほど
        //今日の授業は空白を含んだ文字列をそのまま読み込むという内容です
        // これ、文字列読み込みループのとちゅうで空白見つける処理してない?
        // 一度、aに完全に入力をし終わってからforの処理に入ろう。
        // 
        // というか授業終わりですね
        //授業おわっちゃったんでえんき！！　ありがとね
        // りょうかい。なんもー
        if( fgets(a, sizeof(a), stdin)== NULL)
            break;
        
        else{
            //ho-n
            // null 文字は'0'ではなく'\0'です！！！
            // nはいらない
            // バックスラッシュは特別な文字を表現するときに使うんだけど、普通の文字と区別するためにバックスラッシュをつけている
            // バックスラッシュを普通の文字として表したいときは'\\'って2つ打つとできるよ
            a[strlen(a) - 1] = '\0'; //改行文字→ヌル文字

            // このままだと、二個目以降のの単語の最初の位置がわからないので、まずその変数を定義しよう
            int n = 0;
            // 置き換えた先の文字列の変数も定義しますね　　　　iiyo
            char reversed_a[30];
            //                 ↑忘れてた()
            for(int i = strlen(a); i >= 0; i--){
                if(a[i] == ' ' || a[i] == '\0') {
                    // ↑ 最後の単語は空白ではなくnull文字になるからor条件で追加しよう:+1:
                    // これで動かして様子みましょう

                    // で、このときに a[n]からa[i]までが一つの単語になっている(はず)
                    // strncpy(コピー先の文字列の先頭文字のポインタ, コピー元の文字列の先頭いちのポインタ, コピーする文字の数)
                    // "this is a pen"の最初のとき i-n?
                    // ↑   ↑
                    // n   i増やしたら
                    // そう。
                    // ただ、これだとaの先頭から(i-n)までがコピーされてしまうので、 humu...それポインタなんだね
                    // あ、そうなんですよね。reversed_aとreversed_a[0]って同じはずなので
                    // (ちょっt自身無くなってきた)やっぱりポインタじゃないようなので「&」が先頭に必要なようでした(ごめんなさい)
                    strncpy (&reversed_a[strlen(reversed_a)], &a[n], i - n);
                    //       ↑                                ↑

                    // ここで、次の単語の先頭位置がわかっているので
                    // "this is a pen"の最初のとき i-n?
                    //  ↑   ↑
                    //  n   i
                    // を

                    // "this is a pen"の最初のとき i-n?
                    //  ↑   ↑↑
                    //  n   in
                    //  ↑old  ↖︎new i
                    // にしたいんですよ
                    // strlenでもできなくないけど、i+1でokだよ
                    //文字列後ろからみてるから増やしたらだえ
                    // そうだった n += i-nかな(なんか崩壊してしまったので消しちゃいました)
                    n += i - n;
                }
                // ここでnインクリメントしちゃうとiとの違いが無くなってしまう。。。
                
            }

        }
        printf("%s", reversed_a);
        //再起動したのわすれてた
        // cd desktop/oonishi 必要.....
    }

    return 0;
}