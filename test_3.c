#include <stdio.h>
#include <string.h>

int main(void) {
    int kingaku[50];
    char shouhin[50][10], work[10];
    int i, j, n, w_kingaku, goukei;

    for ( i = 0; i < 50; i ++ ) {
        printf("商品コード　金額...");
        if ( scanf("%s%d", shouhin[i], &kingaku[i]) == EOF )
            break;
    }

    n = i;
    for ( i = 0; i < n - 1; i ++)
        for ( j = i + 1; j < n; j ++ )
            if ( strcmp( shouhin[i], shouhin[j]) > 0 ) {
                strcpy(work, shouhin[i]);
                strcpy(shouhin[i], shouhin[j]);
                strcpy(shouhin[j], work);
                w_kingaku = kingaku[i];
                kingaku[i] = kingaku[j];
                kingaku[j] = w_kingaku;
            }

    printf("\n売上明細\n");
    goukei = 0;
    for ( i = 0; i < n; i ++ ) {
        if ( i > 0 && strcmp( shouhin[i], shouhin[i - 1] ) == 0) 
            printf("%s %6d\n","    ", kingaku[i]);
        else
            printf("%s %6d\n", shouhin[i], kingaku[i]);
        
        goukei += kingaku[i];
    }
    printf("合計%7d\n", goukei);
    return 0;

}