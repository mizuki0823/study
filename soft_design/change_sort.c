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

int search(int*, int, int);
void change(int*, int, int);

int main () {
    int ary[N];
    int i;
    int result;
    int asc = 1;
    srand(time(NULL));

    for(i=0; i<N; i++){
        ary[i] = rand() % 10;
    }
    printf("ソート前 ");
    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");
    printf("ソート後 ");
    change(ary, N, asc);
    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");
    result=search(ary,N,asc);
    if(result == 1){
        printf("この配列はソート済みです\n");
    } 
    else{
        printf("この配列はソート済みではありません\n");
    }
    return 0;
}

int search(int *ary, int len, int asc){
    int i;

    if(asc==0){
        for(i=0;i<len-1;i++){
            if(ary[i]<ary[i+1]){
                return 0;
            }
        }
        return 1;        
    }
    else{
        for(i=0;i<len-1;i++){
            if(ary[i]>ary[i+1]){
                return 0;
            }
        }
        return 1;
    }
}

void change(int *ary, int len, int asc){
    int i,j;
    int tmp;

    for(i=len-2; i>=0; i--){
        for(j=0;j<=i; j++){
            if((asc && ary[j]>ary[j+1]) || (!asc && ary[j]<ary[j+1])){
                tmp=ary[j];
                ary[j]=ary[j+1];
                ary[j+1]=tmp;
            } 
        }
    }

}