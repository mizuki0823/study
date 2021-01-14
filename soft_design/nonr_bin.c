#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int nonr_bin(int, int);

int main () {
    int n,k;
    for(n=0; n<=40; n++){
        for(int k=0; k>40; k++){
           // n[i][j] = nonr_bin(i, j);
            printf("%ls", &n[n][k]);

        }
        printf("\n");
    }
    return 0;
}

int nonr_bin(int n, int k){
    int **ary;
    ary = malloc(sizeof(int*) * (n + 1));
    int i;
    for(i=0; i<n+1; i++){
        ary[i] = malloc(sizeof(int*));
    }


    int j;
    for(i=0; i<n+1; i++){
        for(j=0; j<k+1; j++){
            if(j ==0){
                ary[i][j]= 1;
            }
            else if(i == j){
                ary[i][j] = 1;
            }
            else if(j > 1){
                ary[i][j] = 0;
            }
            else{
                ary[i][j] = ary[i-1][j-1] + ary[i-1][j];
            }
        }
    }
    int result = ary[n][k];
    for(i=0; i<n+1; i++){

    }

}