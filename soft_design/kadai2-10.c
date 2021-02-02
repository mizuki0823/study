#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

#define N 15
void kei_sort(char*, int);

int main () {
    //                                                                      ↓ ヌル文字入れました
    char ary[N]={'M','S','J','M','K','S','M','K','A','K','M','K','S','J', '\0'};
    
    printf("ソート前\n");
    // ここ、普通に "%s", ary でいい気がしたこれで全部出力できるので、
    printf("%s\n", ary);

    printf("ソート後");
    kei_sort(ary, N-1);
    printf("%s\n", ary);

    return 0;
}
// 戻り値のかたを書いていない
void kei_sort(char *ary, int len){
    int i,j;
    int idx;
    int tmp;
    int order[len];

    //         ↓ ここ、「<」ですね（int[2] は 0,1 の２個の意味だから、int[len] は 0,1,2,...,len-1 までになる）
    for(i=0; i<len; i++){
        // これはコーディングのTips ですが、多分alt キーを押しながらクリックするとマルチカーソルが使えるので、
        // おんなじようなことをやりたいときにはべんりです!

        // 話が変わるけど、ここは strcmp じゃなくて == 演算子でよい
        // 'M' は文字列ではなく文字なので
        if(ary[i] == 'M'){
            order[i]='1';

        }
        else if (ary[i] == 'K'){
            order[i]='2';
        }
        else if(ary[i] == 'S')
        {
            order[i]='3';
        }
        else if(ary[i] == 'A')
        {
            order[i]='4';
        }
        else if(ary[i] == 'J')
        {
            order[i]='5';
        }
    }
    // ↑ この部分ね「番号を振った」
    
    // これ、置き換えできているので、普通にorderに番号が入っている時と同じようにソートできます
    // ASCII で '1' は 49 ... '5' は 53 なので、ソートできます
    //「置き換え出来てる」とは？うんうんうｍ
    // order には ary からアルファベットを数字にしたものが入っているので、ary のアルファベットを数字に置き換えたものが order にある、の意味
    // ここで、order をソートして、最後に order → ary の置き換えをやれば、終わり！

    //↓orderのソートだね ですです
    //じぶんでコピペしておいてこいつが何ソートだったか忘れたわ :thinking_face:
    // ぼくもわからないのでコピペ元を信用しましょう 基本選択法かな
    //いま見てきたらそこの条件文if((asc && ary[j] < ary[idx]) || (!asc && ary[j] > ary[idx]))だったから困って放置したきがする
    //                                ^^^^^^^^^^^^^^^^^ この部分になるのではと思いました
    // 今回は昇順なので、多分 asc が昇順なら1、降順なら0とかいう設計だったはず、ということから考えると、
    //        ↓ここはlen-1かもしれん というと？　理由はよくわかんないけどコピペ先がそうだった　なぜ？
    // あ、そうか、確かに len - 1 だ 基本選択法は、i より 大きいところ(授業スライドでいう右側)に order[i] より大きい値があるかを探して、あれば置き換える
    // というやり方だから、最後は一番右になるので、置き換えるものがないんだ まあそんな感じだと思う
    //左側の上限値はlen-1ってことね　じゃあこんな感じでおけかな
    // コンパイルして動かしてみましょう　いいかんじ
    // 良さそう
    for(i=0; i<len-1; i++){
        idx = i;
        for(j=i; j<len; j++){
            if(order[j] < order[idx]){ // だとしたらここの条件おかしくないか…？
                idx = j;
            }
        }
        tmp = order[i];
        order[i] = order[idx];
        order[idx] = tmp;
    }

    // ソートができた(はず)なので あとは '1' → 'M' に戻したものを ary に代入しましょうか
    // ここでマルチカーソルを使って ary order を置き換えると幸せに楽にできるかと
    for(i=0; i<len; i++){
        // これはコーディングのTips ですが、多分alt キーを押しながらクリックするとマルチカーソルが使えるので、
        // おんなじようなことをやりたいときにはべんりです!

        // 話が変わるけど、ここは strcmp じゃなくて == 演算子でよい
        // 'M' は文字列ではなく文字なので
        if(order[i] == '1'){
            ary[i]='M';

        }
        else if (order[i] == '2'){
            ary[i]='K';
        }
        else if(order[i] == '3')
        {
            ary[i]='S';
        }
        else if(order[i] == '4')
        {
            ary[i]='A';
        }
        else if(order[i] == '5')
        {
            ary[i]='J';
        }

        // :clap:
    }
}
// かだいをまだやっていないので確認してきます
//にっこり
//プログラムじゃないんだけど質問９の
//振り分けで「1要素の範囲と残りの範囲」となるのはどのような場合か？がわからんのよね　おけその間にこいつの挙動を確かめとくね
// ソートアルゴリズム(3).pdf の 3ページの図で、R と L がすれ違うのが端になる時っていったらわかるかな ん　いや違うかも　ちょっとまって
// 多分、11111118 みたいに大量に同じ値があると、それは端になるのかな…？
// 振り分けの関数で、途中経過を printf しながら↑ の値を振り分けしてみますか…
// 最初の L:1, R:0, p:1 は 1要素と残りの範囲に振り分けられているといえそう…？
// でも、2つめでR:-3 ってなんだこれ…、、
// ちょっと調べてきたんだけど、「1要素の範囲と残りの範囲」になると最悪(一番時間がかかる)計算量になるので、
// その最悪時間計算量になるときというのは、配列の最大値/最小値がピボットになるときらしい
// 「配列の最大値/最小値がピボットになるとき」ということでいい気がする
//課題のコードをgit hubにあげんのってだめだったっけ　そうね　そういえばトレンドにgit hubあったから何事かとおもった　あほやん　
// https://togetter.com/li/1659308 ← これみたら息が詰まりました　おつです
// ネットは怖いですね ね 今日のところはここら辺にしますか おつかれさまでした
// 盗まれたら0点になりかねないので 自分の年収予測したさに仕事で書いた企業秘密のコードをあげてしまった人(三井住友銀行のシステム開発の委託先)がいるらしい
// 公開にするのはよくない気がする
// あ、多分課題はしない方がいいね、それ以外はコミットしときましょ
// これくらいで大丈夫ですかね　コミットしときますか しばらくしてないみたいだし（）
//たしかに…？　今 Discord で読んでたリンク送った　ありがとー　そうですね
//そこはたしかに変よね
//↑どうだった？　うーん振り分けがあんまり…
//M=1, K=2, S=3, A=4, J=5ってしてidxができたんだけど結局どうソートするかわからなくなった 
//idxはソートできるけどだから何じゃ？ってなった
// 「idxはソートできる」はどういう意味？
//idxっていう配列を作って、ary[i]の中身に応じて番号を振ったんだよね。だからidxをソートしてやったらとりあえず整列できるかなって
//数字だったらソートできるじゃない？ごめんorderだったわ
// idx は普通の int 型の変数のようだけども…
// なるほどなるほど