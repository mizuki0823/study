#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

#define MAX_LEN 1000

MATRIX* allocM(int nrow, int ncol){

    MATRIX *m = malloc(sizeof(MATRIX));
    m->ncol = ncol;
    m->nrow = nrow;
    m->data = malloc(sizeof(double*) * m->nrow);
    int i,j;
    for(i=0; i < m->nrow; ++i){
        m->data[i] = malloc(sizeof(double) * m->ncol);
        for(j=0; j < m->ncol; j++){
            m->data[i][j] = 0;
        }
    }
    return m;
}

void freeM(MATRIX* m){
    int i;
    for(i=0; i < m->nrow; ++i){
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void printM(MATRIX* m){
int i,j;
    for(i=0; i<m->nrow; i++){
        for(j=0; j<m->ncol; j++){
            printf("%lf ", m->data[i][j]);
        }
        printf("\n");
    }
}
MATRIX* addM(MATRIX*m1, MATRIX*m2){
    int i,j;
    if(m1->nrow != m2->nrow || m1->ncol !=m2->ncol){
        return NULL;
    }
    else{
        MATRIX *result = allocM(m1->nrow, m1->ncol);

        for(i=0; i<m1->nrow; i++){
            for(j=0; j<m1->ncol; j++){
                result->data[i][j] = m1->data[i][j] + m2->data[i][j];
            }
        }
        return result;
    }
}

MATRIX* subM(MATRIX*m1, MATRIX*m2){
    int i,j;
    if(m1->nrow != m2->nrow || m1->ncol !=m2->ncol){
        return NULL;
    }
    else{
        MATRIX *result = allocM(m1->nrow, m1->ncol);

        for(i=0; i<m1->nrow; i++){
            for(j=0; j<m1->ncol; j++){
                result->data[i][j] = m1->data[i][j] - m2->data[i][j];
            }
        }
        return result;
    }
}

MATRIX* mulM(MATRIX*m1, MATRIX*m2){
    int i,j, k;
    if(m1->ncol != m2->nrow){
        return NULL;
    }
    else{
        MATRIX *result = allocM(m1->nrow, m2->ncol);

        for(i=0; i<m1->nrow; i++){
            for(j=0; j<m2->ncol; j++){
                for(k=0; k<m1->ncol; ++k){
                    result->data[i][j] += (m1->data[i][k] * m2->data[k][j]);
                }
            }
        }
        return result;
    }
}

MATRIX* transM(MATRIX*m){
    int i,j;
    MATRIX *result = allocM(m->ncol, m->nrow);

     for(i=0; i<m->ncol; i++){
            for(j=0; j<m->nrow; j++){
                result->data[i][j] = m->data[j][i];
            }
        }
        return result; 
}

MATRIX* loadM(FILE *fp){
   char row[MAX_LEN];
   int nrow,ncol,cncol;

   while (fgets(row, MAX_LEN, fp) != NULL) {
       int len = strlen(row);
       if(len < MAX_LEN-1 || (len == MAX_LEN && row[MAX_LEN-2] == '\n')){
           nrow++;
           ncol=0;
           for(int i=0; i<len; i++){
               if(row[i]== ' '){
                   ncol++;
               }
           }
           ncol++;
           if(cncol == 0){
               cncol = ncol;
           }
           else{
               printf("ncol=%d cncol=%d\n", ncol, cncol);
               if(ncol != cncol){
                   printf("列数が異なる\n");
                   
                   return NULL;
               }
           }
       }
       else{
           printf("行の最大文字数を超えた\n");
           return NULL;
       }

   }

    MATRIX *loaded = allocM(nrow,ncol);

    rewind(fp);
    for(int i=0; i<nrow; i++){
        for(int j=0; j<ncol; j++){
            fscanf(fp, "%lf", &loaded->data[i][j]);
        }
    }
    return loaded;   
}

void saveM(FILE *fp, MATRIX*m){
    int i,j;
    for(i=0; i<m->nrow; i++){
        for(j=0; j<m->ncol; j++){
            //                  ↓ ポインタになっている
            fprintf(fp, "%lf ", m->data[i][j]);
        }
        
        fprintf(fp, "%lf", m->data[i][m->ncol-1]);
        if(i != m->nrow-1){
            //          ↓ 文字列ではなく文字になっている（fputc とかなら文字 '' でいいけど、fprintf なら文字列 "" じゃないといけない）
            fprintf(fp, "\n");  //ここはこれでいいかな
            // いいと思う
        }
    }
}