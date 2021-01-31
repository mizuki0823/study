#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)
#define MAX_LEN 1000

struct matrix{
    int nrow;
    int ncol;
    double **data;
};

typedef struct matrix MATRIX;

MATRIX* allocM(int nrow, int ncol);
void freeM(MATRIX* m);
void printM(MATRIX* m);
MATRIX* addM(MATRIX* m1, MATRIX* m2);
MATRIX* subM(MATRIX* m1, MATRIX* m2);
MATRIX* mulM(MATRIX* m1, MATRIX* m2);
MATRIX* transM(MATRIX* m);
MATRIX* loadM(FILE *fp);
MATRIX* saveM(FILE *fp, MATRIX* m);

// こっちにも main 関数あったから怒られてますね
//gyouretu.cっている？
int main_old () {
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
    if(fm == NULL){
        freeM(fm);
    }
    printf("loaded\n");
    printM(fm);

    return 0;
}

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

//先生のloadM見てきたんだけど私の仕様みたしてないかもそもそもretu
// なるほど…
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

MATRIX* saveM(FILE *fp, MATRIX*m){
    int i,j;
    for(i=0; i<m->nrow; i++){
        for(j=0; j<m->ncol; j++){
            fprintf(fp, "%lf ", &m->data[i][j]);
        }
        
        fprintf(fp, "%lf", m->data[i][m->ncol-1]);
        if(i != m->nrow-1){
            fprintf(fp, '\n');  
        }
    }
}