#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

#define N 7

// quick sort 用のファイルを作ることになるのかな
// いや、このファイルに関数を追加することになりそう
//huri2はともかくhuriはできてそう

void huri(int*, int, int);
void huri2(int*, int, int, int, int*);
// 次のスライド EX3 に仕様が書いてあった
//がってん
void quick_sort(int*, int, int);
void quick_sort_part(int*, int, int, int, int);

int main () {
    int ary[N]={1,1,1,1,1,1,8};
    int ary2[N];
    int lr[1];
    int i;
    int asc=1;
    int start=2;
    int end=7;

    // for(i=0; i<N; i++){
    //     ary[i] = rand() % 10;
    // }
    // 1,1,1,1,1,1,8 みたいな配列を作ってそれをソートしてみますか

    
    printf("振り分け前 ");
    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");

    printf("振り分け後 ");
    //huri(ary, N, asc);
    //huri2(ary2, start, end, asc, lr);
    quick_sort(ary, N, asc); // ← ソートしてみたい

    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");
    return 0;
}

void huri(int *ary, int anum, int asc){
    int p,cp;
    int L=0;
    int R=anum-1;

    p = ary[anum/2];

    if(asc==1){
        while (1){
            while(ary[L]<p)L++;
            while(ary[R]>p)R--;

            if(L<=R){
                cp = ary[L];
                ary[L] = ary[R];
                ary[R] = cp;
            }else{
                break;
            }
            L++;
            R--;

                if(L>R){
                    break;
                }
        }
        printf("L:%d, R:%d, p:%d\n", L, R, p);
    }
    else{
        while (1){
            while(ary[L]<p)L++;
            while(ary[R]>p)R--;

            if(L>=R){
                cp = ary[L];
                ary[L] = ary[R];
                ary[R] = cp;
            }
            L++;
            R--;

            if(L>R){
                break;
            }
        }
        printf("L:%d, R:%d, p:%d\n", L, R, p);
    }
}
//huriはたぶん先生を追っかけて終わった
// なるほど
//start--endの位置までで振り分けをするやつがhuri2かな
// だと思う
// コピペでちょっと直して実装する感じだそうですが、どうします？ りょうかい だよね(それ思った)
//そんなに変更点がないような気もするのでそうしようかな
//あんまりわかってないから１からでもいいんだけど普通に間に合わなそう した


void huri2(int *ary, int start, int end, int asc, int *lr){
    int p,cp;
    // ここが start になるのかな あ、そういう意味ではなく、L の初期値が 0 ではなくて start になるってこと（）
    //start引数だあそっかこれってLがstartでRがendになる以外にやらなきゃいけないことある？
    // ないと...思う...(けどこれってこんなに単純な話でEX2が終わっていいのか...と思っています)
    //start から endまでの配列でふりわけってそこに含まれない要素を捨てる（新しい配列に振り分けた分だけ入れるって思ったけど違うみたいですね）
    // "捨てる" はどういう意味で使ってる？
    // 引数で渡された配列を操作してるので start ~ end 以外の範囲はそのまま残るかな
    //うん　lrはただのLとRの記録用らしい
    int L=start;
    int R=end-1;

    p = ary[(start+end)/2];

    if(asc==1){
        while (1){
            while(ary[L]<p)L++;
            while(ary[R]>p)R--;

            if(L<=R){
                cp = ary[L];
                ary[L] = ary[R];
                ary[R] = cp;
            }else{
                break;
            }
            L++;
            R--;

                if(L>R){
                    break;
                }
        }
        lr[0]=L;
        lr[1]=R;
    }
    else{
        while (1){
            while(ary[L]<p)L++;
            while(ary[R]>p)R--;

            if(L>=R){
                cp = ary[L];
                ary[L] = ary[R];
                ary[R] = cp;
            }
            L++;
            R--;

            if(L>R){
                break;
            }
        }
        lr[0]=L;
        lr[1]=R;
    }
    // 表示してみましょ (コピペしてきた)あ、もうしてきたのね ですね
    printf("L:%d, R:%d, p:%d\n", L, R, p);
    

}

void quick_sort_part(int* ary, int anum, int asc, int left, int right){
    //int p;
    // ２個のはず なんで？lr[0]とlr[1]で２個じゃない？
    // L と R の2個必要なので
    //     ↓ ここ 2 に変えて大丈夫ですかね
    int lr[2]; // ← コアダンプの理由これだ

    // 1. 与えられた列の要素数が1以下の場合、この手続きを終了する
    if(anum<=1){ // ← anum は 常に ary の長さなので、left right から判定しないと行けないですね
        // いや違うのか

        // break は ループ の終了なので、 今は関数 return ですね
        // うん、何も返さないので、return; でOK
        //そうでした…関数の終了っておけvoidでもそれでいいのね
        return;
    }

    // 2. 与えられた列の中からピボットを決め、振り分けを行う
   // p = ary[anum/2]; // !ピポットも、昇順降順関係ないですね
    // 決めなくてもよかった

    // quick_sort_part 関数には left right の引数があるので…？ ですね(このあとの3,4で使うはず)
    //lrなきゃだめ？
    huri2(ary, left, right, asc, lr);            

    //             ↓ これで lr を使うってことだと思います       lr[0]=L,lr[1]=R
    // 3. 列の前方（R以前の要素集合）をこの手続きでソートする
    // !"ソートする" というのは この手続き == quick_sort_part を呼び出す ということです
    //                              ↓ ここが いつも 0 とは限らないですね quick_sort_"part" で left と right が引数にあるので…？
    //  !left ~ lr[1] の範囲なので…？
    quick_sort_part(ary, right-left+1, asc, left, lr[1]); // ← ここで、次の呼び出しで left right が変わっているから、right-left+1 でいいんだ
    //                   ↑ やっぱりここで長さを変えるべきっぽい そう 無限ループ(再起呼び出し？)になる
    //                      このままだと一生anum変わんないもんね
    //                      ここか
    // だからlr使わなきゃだめなんか ですね

    // 4. 列の後方（L以降の要素集合）をこの手続きでソートする
    quick_sort_part(ary, right-lr[0], asc, lr[0], right);

        // これでいいはず？ ソートしてみたいっすね
    // p が 1 になっているということは、
}

// あれま どこ間違ったかね
// あー、そうか、いや、ん(スライドみてます)
// 関数の呼び出しで left lr[1] とかで長さ変えてるから、 right-left+1 でいいのか
//先生right-left+1とかしてるけどそれっていいのか？
void quick_sort(int* ary, int anum, int asc){
    quick_sort_part(ary, anum, asc, 0, anum-1);
}