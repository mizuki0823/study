#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int f(int, int);

int main () {
    int n1, n2 = 0;

    while (1){
        printf("入力");
        if ( scanf("%d",&n1) == EOF)
            break;
        n2 += f( n1, n2);
    }
    printf("\n出力 %d\n", n2);

    return 0;
}

int f(int a, int b){
    return a < b ? b - a : a - b; 
}


/* A as well as B == not only B bat also A

    word order "語順"

    on board "船上（乗り物の上に乗ってる）"

    He was placd under a series of examinations. "彼は一連の調査のもとに置かれた"

    as a source of information "情報元として"

    Since Japan's doors to foreign countries were closed at that time, his path was not smooth.
    "当時の日本は外国への戸を閉じていたので、彼の通過はスムーズではなかった"

    played an role "役割を果たす"
    
    behind the scenes "〰の舞台裏で"

