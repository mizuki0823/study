#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>

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

    for(i=0; i<N; i++){
        ary[i] = rand() % 10;
    }
    printf("ソート前");
    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }
    printf("\n");
    printf("ソート後");
    selection_sort(ary, N, 1);
    for(i=0; i<N; i++){
        printf("%d ", ary[i]);
    }

    result=search(ary,N,1);
    if(result == 1){
        printf("この配列はソート済みです\n");
        for(int k=0; k<5; k++){
            printf("%d,", ary[k]);
        }
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
    int i,j,sorted,maxnum,minnum,cp,idx;

    if(asc==0){
        for(i=0;i<len-1;i++){
            if(ary[i]<ary[i+1]){
                sorted = i+1;
                for(j=sorted;j<len-1;j++){
                    if(ary[j]>ary[j+1]){
                        maxnum = ary[j];
                    }
                    else{
                        maxnum = ary[j+1];
                    }
                }
                cp = sorted-1; 
                ary[sorted-1] = ary[maxnum];
                ary[maxnum] = cp;
            }
        }
    }
    else if(asc==1){
        for(i=0; i<len-1; i++){
            if(ary[i]>ary[i+1]){
                sorted = i+1;
                for(j=sorted;j<len-1;j++){
                    if(ary[j]<ary[j+1]){
                        minnum = ary[j];
                    }
                    else{
                        minnum = ary[j+1];
                    }
                }
                printf("minnum=%d\n",minnum);
                cp = ary[sorted-1]; 
                printf("%d\n", ary[sorted-1]);
                printf("%d\n", cp);
                ary[sorted-1] = ary[minnum];
                ary[minnum] = cp;
            }
        }
    }

}