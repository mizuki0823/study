#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// #include "matrix.h" // ← matrix.h / matrix.c は必要ですね
// matrix.c がない…？
#include "gyouretufuho.c" // こうかな？ gcc -o bin/gauss gauss.c でOKです　これgaussf.cかも　gaussf.cは直接インクルードするんじゃなくmatrix.hをインクルードすればついてくるからいいのか
// 依存している関係的には、gauss.c の main が gyouretu.c や gaussf.c の関数を必要としているので、gauss.c で良いはず…？
#include "gaussf.c" //ここで直接インクルードしてます（そういう話ではなく…？） c を直接読み込むチートします 面倒なので時間短縮  すまぬ :ok_hand:
                    //そんなことができるんかあってことはgauss.cだけ普通にコンパイルすればいいの？

                    //つまり今回使うのはgauss.c,gaussf.c,gyouretufuho.c,matrix.hでおっけー？（←gyouretu.cってgyouretufuho.cとgyouretumain.cに分割してあるんだけどそうじゃなくてgyouretu.cを使うの？）
                    // です(まあ、チート #include しているので、gcc -o bin/gauss gauss.c でOKです())
                    // 分割してあったの知らなかったわ… fuho でOKです　OK
int main () {
    MATRIX *B = allocM(3,1);
    B->data[0][0] = 10;
    B->data[1][0] = 7;
    B->data[2][0] = 0;

    char fname[256];
    FILE *fp;
    scanf("%s", fname);
    if((fp = fopen(fname, "r")) == NULL){
        printf("開けませんでした\n");
        exit(EXIT_FAILURE);
    }
    MATRIX *fm = loadM(fp);
    if(fm==NULL){
        printf("しっぱい\n");
        return 0;
    }

    // ここで gauss 関数を呼び出す感じかな
    //このときの引数って読み込んだファイルのやつだからfname？
    // fname ってなんじゃ？
    //loadMでファイルの名前を入力してそのファイルを開くっていうファイルだからちがうきがした　MATRIX*fmに代入してるもんね　はーい
    // loadM にファイルポインタを渡して、そこで loadM はファイルポインタから読み込んでいるので、
    // fm で良いかなと思いました
    // 　　↓ 関数定義ではなく呼び出しなので、型は書かなくて大丈夫
    // もう一つ、右辺の行列がいるね
    //それってもう１つ別のファイルに書いてloadMをもっかいやるって感じ？
    // それでもいいし、allocM で即席で行列作ってもいいと思う←上でやってるからそうしよう
    printM(fm); // 前と後を比べてみようの会 とりあえずこれでできるかな？
    // 多分できる　正解かわかるようにスライドと一緒にしてみた :+1:
    //分割コンパイル忘れたかも
    gauss(fm,B);
    printM(fm);

    if(fclose(fp)==EOF){
        printf("閉じれませんでした\n");
        exit(EXIT_FAILURE);
    }
    // fm != NULL の間違い…？(今見て思った)tasikani
    if(fm != NULL){
        freeM(fm); // ← ここ
    }
    printf("loaded\n");
    // freeM(fm) しているので、その後に表示しようとしても既にメモリ解放されているような…？
    //printM(fm);

    free(B);
    
    return 0;
}