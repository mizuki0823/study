#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char in_moji[80];
    FILE *gf_pt;

    if((gf_pt = fopen("gakusei.dat", "w+")) == NULL) {
        printf("FILE OPEN ERROR\n");
        exit(EXIT_FAILURE);
    }

    printf("データを入力してください（終了は^D）\n");
    rewind(stdin);
    while((scanf("%s", in_moji)) != EOF){
        fputs(in_moji, gf_pt);
    }

    printf("データを表示します\n");
    rewind(gf_pt);
    while((fgets(in_moji, 80, gf_pt)) != NULL){
        printf("%s\n", in_moji);
    }

    if(fclose(gf_pt) == EOF){
        printf("FILE CLOSE ERROR\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}