#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int search3(int*, int, int);

int main () {
    int *ary;

    return 0;
}

int search3(int* ary, int len, int asc){
    // 2分法コピってきて
    int p1, p2, i;

    p1 = 0;
    p2 = len-1;

    while (1){
        if(p2 - p1 < 3){
            if (ary[p1] == asc) {
                return p1;
            }

            if (ary[p1+1] == asc) {
                return p1+1;
            }

            if (ary[p1+2] == asc) {
                return p1+2;
            }

            return -1;
        }

        // int m = p1+p2/2; // これは 1/2

        // m が m1 と m2 に分かれます
        int m1 = p1 + (p1+p2)/3;// 1/3 の場所
        int m2 = p1 + (p1+p2)*2/3;// 2/3 の場所

        // 3等分のうちの 左
        // if(ary[m1] > asc){　← if
            //right = 
            //}あと２分なんですけど提出してきちゃだめですかこめんと
            
            if(ary[m1] > asc){
                right = p - 1;
            }
            // しょうがないっすね

        // ary[m1] == asc
            // return p1

        // 真ん中
        // ary[m2] > asc
            // left = 
            // right =
        

        // ary[m2] == asc
            // return m2;

        // どれにも当てはまらなかったとき
        //　一番右
        left = 


        // if(ary[m] == obj){
        //     return m;
        // }
        // else if(ary[m] < obj){
        //     p1 = m+1;
        // }
        // else{
        //     p2 = m-1;
        // }
}
}