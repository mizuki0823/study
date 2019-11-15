#include <stdio.h>
#include <string.h>

int main (void) {
    char moji_1[4][10], moji_2[4][10],work[10];
    int i, n, k;

    for ( i = 0; i < 4; i ++ ) {
        printf("[%2d] ２つの文字列　（CTRL＋Dで終了）", i + 1);
        if( scanf("%s%s", moji_1[i], moji_2[i] ) == EOF ) {
            putchar('\n');
            break;
        }
    }
    n = i;
    
    for (i = 0; i < n; i ++ ) {
        if (strlen( moji_1[i] ) > strlen( moji_2[i] ) ) {
            strcpy(work, moji_1[i] );
            strcpy( moji_1[i], moji_2[i] );
            strcpy( moji_2[i], work );
        }
        for (k = 0; k < strlen(moji_1[i]) ; k ++) {
            if (moji_1[i][k] == '?' || moji_2[i][k] == '?' )
                continue;
            if ( moji_1[i][k] != moji_2[i][k] ) {
                printf("[%2d] %s　は %sの先頭と不一致\n", i + 1, moji_1[i], moji_2[i]);
                break;

            }
        }
        if ( k >= strlen(moji_1[i] ) )
            printf("[%2d] %sは%sの先頭と一致\n", i + 1, moji_1[i], moji_2[i]);
    }
    return 0;
}