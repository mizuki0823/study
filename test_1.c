#include <stdio.h>
#include <string.h>

int main (void) {
    char moji_1[3][10], moji_2[3][10], work[10];
    int i, n, k;

    for ( i = 0; i < 3 ; i++) {
        printf("[%2d]２つの文字列　（CTRL+Dで終了）...", i + 1);
        if ( scanf("%s%s", moji_1[i], moji_2[i]) == EOF ){
            putchar('\n');
            break;
        }
    }
    n = i;

    for (i = 0; i < n; i ++) {
        if ( strlen( moji_1[i]) > strlen( moji_2[i]) ) {
            strcpy( work, moji_1[i] );
            strcpy( moji_1[i], moji_2[i] );
            strcpy( moji_2[i], work);
        }

        if ( strncmp( moji_1[i], moji_2[i], strlen(moji_1[i] ) )  == 0)
            printf("[%2d] %s　は %s　の先頭と一致\n", i + 1, moji_1[i], moji_2[i]);
        else
            printf("[%2d]%sは%sの先頭と不一致\n", i + 1, moji_1[i], moji_2[i]);
    }
    return 0;
}