#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "matrix.h"2重 include されているようなのでひとまずこっちでの include やめますか　りょ

MATRIX* gauss(MATRIX*A, MATRIX*B){
    int k, i, j;

    if(A->nrow != A->ncol){
        return NULL;
    }
    if(A->nrow != B->nrow){
        return NULL;
    }

    // まずこれ↓のループは、行列計算(2).pdfの4 ページ目の3 の、左下側を 0 にするための計算っていうのはOK?
    //どうやってるかはわからないけど結果そうなるのはOK　なるほど１行＊３ー２行みたいなやつ？ふむふむ
    // そうそう、そういうやつ
    //今はその下半分が０になる処理が出来てるかどうかみようってやつね？
    // なるほどね
    //普通にmainのなかで配列作ってやろうとしたらloadM使いましょうねって言われたよ
    //これは…？hou
    // nan になっているので、ありえない計算(0で割るとか)がされたっぽい

    for(k=0; k < A->nrow-1; k++){//k列目の前進消去
        // k = 0 だとすると、
        for(i=k+1; i < A->nrow;i++){//i行目の消去
            double alpha = A->data[i][k] / A->data[k][k];

            for(j=0; j < A->ncol; j++){//j行目の消去
                A->data[i][j] -= alpha /
                A->data[k][k] * A->data[k][j];
            }
            B->data[i][0] -= alpha /
            A->data[k][k] * B->data[0][i];
        }
        // ↑の処理がされることで、一番左の1列を0にしてる ありがとうございました お疲れ様です
        //ここの計算がへんってことよね　k+1しただけで終わらなくなったのはなんなんだろう　うーん
        // 謎です…
        // ですね…　これはどうしたら…？反応がないです　ぽいした :ok_hand:
        // （先生も nan になってた ）そうね… :pleading_face:
        // Ctrl と C を押したら終了できないかな
        // ゴミ箱ボタンでターミナルごと　
    }
    

}

//とりあえず先週は先生の写したはず
// なるほど (スライドみてます、ちょっと待ってね)
//　これが何をしとるんかよくわからないんよね　おけ