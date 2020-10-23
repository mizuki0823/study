#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

float printFloatBits(float);

typedef union {
        float tag;
        unsigned char expression[4];
}NUM;

int main () {
    float f = 0.8;
    printFloatBits(f);
    return 0;
}

float printFloatBits(float tag){
    NUM x;
    x.tag = tag;
    int i, j;
    for(i=3; i>=0; i--){//リトルエンディアンなので最後の要素から
        for(j=7; j>=0; --j){
            printf("%d", (x.expression[i] >> j) % 2);
        }
    
    }
    printf("\n");

    if(0 <= printFloatBits(tag) < 0.5){
        return 2*printFloatBits(tag);
    }else if(0.5 <= printFloatBits(tag) < 1.0){
        return(1-printFloatBits(tag));
    }
}

