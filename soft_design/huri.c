#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

#define N 10

void huri(int*, int, int);
void huri2(int*, int, int, int, int*);

int main () {
    int ary[N];
    int ary2[N];
    int lr[1];
    int i;
    int asc=1;
    int start=0;
    int end=9;

    for(i=0; i<N; i++){
        ary[i] = rand() % 10;
    }

    
    printf("振り分け前 ");
    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");

    printf("振り分け後 ");
    huri(ary, N, asc);
    huri2(ary2, start, end, asc, lr);

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

void huri2(int *ary, int start, int end, int asc, int *lr){
    int p,cp;
    int L=0;
    int R=end-1;

    p = ary[(start+end)/2];

    

}