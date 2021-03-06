#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main (int argc, char **argv) {
    // コマンド問題
    // argv → char** → char のポインタのポインタ
    // &argv → char*** → char のポインタのポインタのポインタ

    for(int i=0; i<argc; i++){
        printf("%s ",argv[i]); // でみてみましょうか
    }
    
    //でたー！👏
    // あと質問なければ次行きますか
    //いきましょう
    //ポインタむずくないですか？　うーんなるほど…　次行く前にちょっと離席するわ :man-gesturing-ok:←どういう意味なんですか？ discord で送ったもどった
    // ポインタというか、文字と文字列の扱いが printf で同じように見えるけど、実際は全然、全くもって違うということがさらにややこしくさせてるね → 36, 37行目の話
    // あと、null 文字で文字列の終わりを示せるっていうのもポインタと合わせるとうまく文字列を使えるようになるのもややこしくさせてるね
    // ここら辺の仕様がわかってないと、"うまく"使えないというアレ
    //argcって入ってる数だから小なり
    //なんか警告された　なんで%d？　ほんとにint型なの？
    // `*argv[i]` は int 型ですね と言われてる
    //  ↑ ここ (int型というよりはポインタだね) 
    // ちょっと図で説明したほうがいいかもね Discordで画面共有するか
    //どうやるんだっけか とりあえずかけるわ
    // 見えてる？　てる　なるほどー　素直に*argv[i]すると最初はaa bbb ccがある場所を示すポインタがでてくるんだ？という解釈でおけ？
    // `argv[i]` (*なし)だとそういうことになる
    // `*argv[i]` だと、「アドレスの先の値」になる
    //argv[2]の中身が*argv[2]で出せてそれが500（bの文字列が入ってるアドレス）
    // argv[2] が 500 （`printf("%p", argv[2])` が 500 の16進表記 0x1f4 になる）とき、500 (0x1f4) には 'b' (int (98)) が入っているってことになるね
    // printf("%c", 〜〜〜); のとき、〜〜〜には表示する値が入るけど、
    // printf("%s", 〜〜〜); のとき、〜〜〜にはアドレスの値が入る
    // という違いがあるのを頭の片隅に入れておいたほうがいいかも
    // というわけになるのですが…わかりますかね
    //ふむ　*hogeで中身を見ようとしたら中身がポインタだったときはそのポインタに格納されている値がでる？
    // 〜〜(上と同じ)のときは〜〜(上と同じ)になるというより、
    // printf("%〜", 〜〜)での〜〜がポインタになるかどうかで、%〜の方を変えないといけない
    //なるほど　今回はprintf("%s", 〜〜〜); のとき、〜〜〜にはアドレスの値が入るにあたるから*をつけるとおかしくなる？
    // ですね、「*をつけるなら、値 になるので、%c になる」ということもできる
    //　それでint型って言われたってことか（500 (0x1f4) には 'b' (int (98)) が入っている）
    // だね
    //やっとわかった
    // ですね、ちょっと離席します
    // 戻りました
    //こうですか？
    // 実行してみましょう
    //なんかポインタがでた　こうかポインタ変数やもんね
    //プログラムの名前がでたね
    // これが答えですね
    // ./test1.9 aa bbb cccc
    // って実行すると、argv からは↑の4つの文字列が取れるはずなんですけど、せっかくなので、4つ全部表示できるようにしてみますか ← これは "文字列" を4回 表示することになるので、for なり while なりのループになります
    //今はむりな感じ？
    // 今は ./test1.9 しか出てこないと思う
    //それでちょうど９文字だからかな　そうでした（混ざったわ）
    // ううん、それは関係ない(下のはまた別の(文字と文字列の)お話なので)
    //そうねやっぱ出なかった　今はargv[0]の中身の/.test1.9しか出ないよってことか
    // ですね
    //いまこそforのとき？です
    //アドレスが&で中身が*だっけ
    //文字列なん？　それは見た目でわかるやつ？　ふむ　そうよね
    //文字列だと文字とどう違うん？↓
    // 文字列: アドレスに入っているのは文字だけど、そこからヌル文字まで文字列が続いてる
    // 文字: アドレスに入っているのは文字で、そのさきは別物

    // 文字
    // char *charactor = malloc(sizeof(char));
    // scanf("%c", charactor);
    // scanf で 1文字入力したとすると、
    // charactor が 1000 のとき、1000 には 文字が入ってるけど、1001 は管轄外(確保しているメモリの範囲外なので、このプログラムからは使えない / 他のプログラムが使っている（かもしれない）)

    // 文字列
    // char *string = malloc(sizeof(char) * 10); // 9文字 + 1ヌル文字分
    // scanf("%s", string);
    // scanf で 9文字入力したとすると、
    // charactor が 1000 のとき、1000 から 1009 までには文字が入っていて、 1010 には ヌル文字が入っていて、1011 は管轄外

    //ということは文字列ごと全部見ようってこと？forですか？
    // そういうことー
    // 問題は argv[0] なので、0番目の文字列を見るってことですね
    // 1つの文字列を見るなら、"%s" で十分です、先頭のアドレスから、ヌル文字を見つけるまで表示してくれるので
    //そうだったのか、ずっと１文字しかやってくれないと思っててfor回してた べんりー　アドレスの内容って%cってこと？
    // これが %c と %s の違いですね アドレスが 1000 だとして、
    // 1000 に入っている内容(値)だけを文字列表示したいときは、printf()で(ポインタではなく)int のときみたいに"値"を渡して、%cにする
    // 1000 からそれ以降に文字列が入っているときは、printf()で"先頭ポインタ(1000)"を渡して、%s にする ← 今回はこれ

    // ポインタ変数に入っているアドレスの内容がみたい！
    // 文字の場合はね、今回は文字列なので…？
    // ですね
    // main の 第二引数はそういうように決まってるって感じだね、見た目(char**)からはわからないかな
    return 0;
}