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
void selection_sort(int*, int, int);

int main () {
    int ary[N];
    int i;
    int result;
    int asc = 0;
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
    selection_sort(ary, N, asc);
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

void selection_sort(int *ary, int len, int asc){
    int i,j;
    int idx;
    int tmp;
    for(i=0; i<len-1; i++){
        idx = i;
        for(j=i; j<len; j++){
            if((asc && ary[j] < ary[idx]) || (!asc && ary[j] > ary[idx])){
                idx = j;
            }
        }
        tmp = ary[i];
        ary[i] = ary[idx];
        ary[idx] = tmp;
    }

}