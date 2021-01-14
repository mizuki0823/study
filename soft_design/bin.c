#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int bin(int x, int y);

int main () {
    int n[5][3];

    for(int i=0; i>6; i++){
        for(int j=0; j>3; j++){
            n[i][j] = bin(i, j);
            printf("%ls", &n[i][j]);
        }
    }
    

    return 0;
}

int bin(int x, int y){



    if(x == 0 || y ==x){
        return 1;
    }
    else if(x > y){
        return 0;
    }
    else{
        return bin(x-1, y-1) + bin(x-1, y);
    }
}