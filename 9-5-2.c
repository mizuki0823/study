#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    struct i_form{
        int suuchi;
        struct i_form *i_pt;
    };
    struct i_form *top_pt, *work_pt;
    int w_suuchi, *q;

    printf("数値を順に入力してください（終了は^D）");

    top_pt = NULL;
    while(scanf("%d", &w_suuchi) != EOF){
        work_pt = (struct i_form *)malloc(sizeof(struct i_form));
        work_pt->suuchi = w_suuchi;
        work_pt->i_pt = top_pt;
        top_pt = work_pt;
    }

    work_pt = top_pt;
    while(work_pt != NULL) {
        printf("%d, ", work_pt->suuchi);
        work_pt = work_pt->i_pt;

    }
    printf("\n");

    work_pt = top_pt;
    while(work_pt != NULL){
        q = work_pt->i_pt;
        free(work_pt);
        work_pt = q;
    }


    return 0;
}