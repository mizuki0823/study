#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main () {
    MATRIX *m1 = allocM(2,2);
    MATRIX *m2 = allocM(2,2);
    MATRIX *m = allocM(2,1);
    m1->data[0][0] = 4;
    m1->data[0][1] = 6;
    m1->data[1][0] = 2;
    m1->data[1][1] = 3;
    m2->data[0][0] = 2;
    m2->data[0][1] = 1;
    m2->data[1][0] = 3;
    m2->data[1][1] = 2;
    m->data[0][0] = 4;
    m->data[1][0] = 2;
    MATRIX *resultadd = addM(m1, m2);
    MATRIX *resultsub = subM(m1,m2);
    MATRIX *resultmul = mulM(m1,m2);
    MATRIX *resulttreans = transM(m);
    printf("resultadd\n");
    printM(resultadd);
    printf("resultsub\n");
    printM(resultsub);
    printf("resultmul\n");
    printM(resultmul);
    printf("resulttrans\n");
    printM(resulttreans);
    freeM(resultadd);
    freeM(resultsub); 
    freeM(resultmul);
    freeM(resulttreans);
    freeM(m1);
    freeM(m2);
    freeM(m);
    //file
    char fname[256];
    FILE *fp;
    scanf("%s", fname);
    if((fp = fopen(fname, "r")) == NULL){
        printf("開けませんでした\n");
        exit(EXIT_FAILURE);
    }
    MATRIX *fm = loadM(fp);
    if(fm==NULL){
        printf("しっぱい\n");
        return 0;
    }
    if(fclose(fp)==EOF){
        printf("閉じれませんでした\n");
        exit(EXIT_FAILURE);
    }
    if(fm != NULL){
        freeM(fm);
    }
    printf("loaded\n");
    printM(fm);

    return 0;
}