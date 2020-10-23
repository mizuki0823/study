#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

void printFloatBits(float);
void printDoubleBits(double);
//double paikone(double);
void paikone(int*, int*);

typedef union {
        float tag;
        unsigned char expression[4];
}NUM;

typedef union {
        double tag;
        unsigned char expression[8];
}DNUM;

int main () {
    //丸め誤差
    printf("丸め誤差\n");
    float a = 1.41421356;
    printFloatBits(a);
    double b = 1.41421356;
    printDoubleBits(b);

    printf("情報落ち\n");
    float j1 = 40000;
    float j2 = 0.001;
    float j3 = j1 + j2;
    printFloatBits(j1);
    printFloatBits(j2);
    printFloatBits(j3);

    printf("桁落ち\n");
    float k1 = 0.041;
    float k2 = 0.400;
    float k3 = k1 - k2;
    printFloatBits(k1);
    printFloatBits(k2);
    printFloatBits(k3);

    printf("パイこね変換\n");
    //double f0 = 0.8, fn = f0;
    int f0a = 4, f0b = 11, fna = f0a, fnb = f0b;
    int i;
    printf("%d : %.52f\n", 0, (double)fna/fnb);
    for(i = 1; i < 53; i++){
        //fn = paikone(fn);
        paikome(&fna &fnb);
        printf("%d : %.52f\n", i, (double)fna/fnb);
    }
    
    return 0;
}

void printFloatBits(float tag){
    NUM x;
    x.tag = tag;
    int i, j;
    for(i=3; i>=0; i--){//リトルエンディアンなので最後の要素から
        for(j=7; j>=0; --j){
            printf("%d", (x.expression[i] >> j) % 2);
        }
    
    }
    printf("\n");
}

void printDoubleBits(double tag){
    DNUM x;
    x.tag = tag;
    int i, j;
    for(i=3; i>=0; i--){//リトルエンディアンなので最後の要素から
        for(j=7; j>=0; --j){
            printf("%d", (x.expression[i] >> j) % 2);
        }
    
    }
    printf("\n");
}

void paikone(int *fna, int *fnb) {
    if(0 <= (double)(*fna)/(*fnb) && (double)(*fna)/(*fnb) < 0.5){
        2 * (*fna);
    }else{
        *fna = 2 * (*fnb - *fna);
    }
}




