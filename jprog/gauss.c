#include <stdio.h>
#include <string.h>
#include <math.h>

#include "matrix.h"

int main () {
    MATRIX *A = allocM(2,2);
    A->data[0][0] = 4;
    A->data[0][1] = 3;
    A->data[1][0] = 2;
    A->data[1][1] = 5;

    MATRIX *B = allocM(2,1);
    B->data[0][0] = 2;
    B->data[1][0] = 1;

    MATRIX *resultgauss = gauss(A,B);
    printf("resultgauss\n");
    printM(resultgauss);

    freeM(resultgauss);
    freeM(A);
    free(B);
    
    return 0;
}