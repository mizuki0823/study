#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char moji;
    FILE *md_fp;

    if((md_fp = fopen("moji_data.dat", "r+")) == NULL) {
        printf("FILE OPEN ERROR\n");
        exit(EXIT_FAILURE);
    }

    while((moji = getc(md_fp)) != EOF) {
        if(isupper(moji)) {
            fseek(md_fp, -1L, SEEK_CUR);
            putc(tolower(moji), md_fp);
            fseek(md_fp, 0L, SEEK_CUR);
        }
    }

    if(fclose(md_fp) == EOF) {
        printf("FILE CLOSE ERROR\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}