#include <stdio.h>
#include <string.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int search(int*, int, int);

int main () {
    int ary[6]={7,6,5,3,2,2};
    int result = search(ary, 6, 0);

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