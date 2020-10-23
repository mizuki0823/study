#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
   char fname[256];
    FILE *fp;
    printf("ファイル名：");
    scanf("%s", fname);
    if((fp = fopen(fname, "r+")) == NULL) {
        printf("ファイルを開けませんでした\n");
        exit(EXIT_FAILURE);
    }

    if(fclose(fp) == EOF){
        printf("ファイルを閉じれませんでした\n");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}