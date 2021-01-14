#include <stdio.h>
#include <string.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int search(int*, int, int);

int main () {
    int ary[6]={1,3,4,5,6,6};
    int result = search(ary, 6, 3);

    if(result == -1){
        printf("探している値は見つかりませんでした\n");
    } 
    else{
        printf("場所は%d番目です\n", result);
    }
    return 0;
}

int search(int *ary, int len, int obj){
    int i,cp;

    if(ary[len-1] == obj){
        return len-1;
    }
    else{
        cp = ary[len-1];
        ary[len-1] = obj;

        for(i=0; ; i++){
            if(ary[i] == obj){
                if(i == len-1){
                    ary[len-1] = cp;
                    return -1;
                }
                else{
                    ary[len-1] = cp;
                    return i;   
                }
            }
        }
    }
}