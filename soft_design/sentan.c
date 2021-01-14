#include <stdio.h>
#include <string.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int search(int*, int, int);

int main () {
    int ary[6]={1,3,4,5,6,6};
    int result = search(ary, 6, 9);

    if(result == -1){
        printf("探している値は見つかりませんでした\n");
    } 
    else{
        printf("場所は%d番目です\n", result+1);
    }
    return 0;
}

int search(int *ary, int len, int obj){
    int i;
    for(i=0; i<len; i++){
        if(ary[i] == obj){
            return i;
        }
    }
    return -1;
}

