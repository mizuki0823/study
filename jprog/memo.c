#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

void point(int *A, int a, int a_data);

enum COURSE {MCH=1, CVL, MAT, ELE, CMP};

int main (int argc, char **argv) {
    int *pt, pt_data, data = 9;

    point(pt, data, pt_data);

    printf("%d %d %d %d %d\n", MCH, CVL, MAT, ELE, CMP);

    int i;
    for(i=argc-1; i>=0; --i){
        printf("%s %d,", argv[i], i);
    }

    return 0;
}

void point(int *A, int a, int a_data){

    A = &a; //アドレスAにaの内容9を入れる
    a_data = *A; //変数a_dataにアドレスAの内容9を代入

    printf("アドレスAの内容=%d\n", *A);

}