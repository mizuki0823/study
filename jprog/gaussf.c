#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

MATRIX* gauss(MATRIX*A, MATRIX*B){
    int k, i, j;

    if(A->nrow != A->ncol){
        return NULL;
    }
    if(A->nrow != B->nrow){
        return NULL;
    }

    for(k=0; k < A->nrow-1; k++){//k列目の前進消去
        for(i=k; i < A->nrow;i++){//i行目の消去
            for(j=0; j < A->ncol; j++){//j行目の消去
                A->data[i][j] -= A->data[i][k] /
                A->data[k][k] * A->data[k][j];
            }
            B->data[i][0] -= A->data[i][k] /
            A->data[k][k] * B->data[0][i];
        }
    }


}