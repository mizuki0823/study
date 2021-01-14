#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

typedef struct {
    char comment[100]; int page; int row;
} BOOKMARK;


int main () {
    FILE *fp;
    BOOKMARK bm;
    BOOKMARK *bm_pointer = &bm;
    fp = fopen("bookmark.dat", "r+");
    if(fp == NULL){
        printf("FILEだめだった\n");
        exit(EXIT_FAILURE); // return EXIT_FAILURE;
    }

    while(fscanf(stdin, "%d %d %s", &bm.page, &bm_pointer->row, bm.comment) != EOF)//（ポインタならアロー演算子、そうでないならドット演算子）
        fprintf(fp, "%d %d %s\n", bm.page, bm.row, bm.comment);
    
    fseek(fp, 0, SEEK_SET);

    while (fscanf(fp, "%d %d %s", &bm.page, &bm.page, bm.comment) != EOF)
        fprintf(stdout, "%d %d %s", bm.row, bm.page, bm.comment);

    if(fclose(fp) == EOF){
        printf("FILEだめだった\n");
        exit(1);
    }
    printf("owari\n");
    return EXIT_SUCCESS;
    
}