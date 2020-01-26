#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)
int pas_t[10][10];
int pas(int [10][10]);
int main () {
    int pas_t[10][10];
    pas(pas_t);
    printf()
    return 0;
}

int pas(int x[][10]){
    for( int i = 0; i < 10; i++ ){
        x[0][i] = 1;
        x[i][0] = 1;
    }

    int n = 9;
    for(int i = 1; i < 9; i++){
        for( int j = 0; j < i; j++){
            x[i][j] = x[i][j - 1] + x[i - 1][j];
        }
    }

}