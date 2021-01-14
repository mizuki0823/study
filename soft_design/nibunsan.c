#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int search(int*, int, int);

int main () {
    int ary[9]={1,2,4,5,6,7,8,9,10};
    int result = search(ary, 9, 3);

    if(result == -1){
        printf("探している値は見つかりませんでした\n");
    } 
    else{
        printf("場所は%d番目です\n", result);
    }
    return 0;
}

int search(int *ary, int len, int obj){
    int p1, p2, i;

    p1 = 0;
    p2 = len-1;

    while (1){
         if(p2 < p1){
            return -1;
        }

        int m = p1+p2/2;

        if(ary[m] == obj){
            return m;
        }
        else if(ary[m] < obj){
            p1 = m+1;
        }
        else{
            p2 = m-1;
        }
    }
}

