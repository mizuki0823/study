#ifndef MATRIX_H
#define MATRIX_H

struct matrix{
    int nrow;
    int ncol;
    double **data;
};
typedef struct matrix MATRIX;

MATRIX* allocM(int, int);
void freeM(MATRIX* m);
void printM(MATRIX* m);
MATRIX* addM(MATRIX* m1, MATRIX* m2);
MATRIX* subM(MATRIX* m1, MATRIX* m2);
MATRIX* mulM(MATRIX* m1, MATRIX* m2);
MATRIX* transM(MATRIX* m);
MATRIX* loadM(FILE *fp);
void saveM(FILE*, MATRIX*);

MATRIX* gauss(MATRIX*A, MATRIX*B);

#endif