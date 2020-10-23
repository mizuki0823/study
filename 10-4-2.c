#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    struct{
        char name[10];
        int ten;
    } gakusei[10], *g_pt;
    int i, j, w_goukei = 0;
    FILE *gf_pt;

    if((gf_pt = fopen("gakusei.dat", "w+")) == NULL) {
        printf("FILE OPEN ERROR\n");
        exit(EXIT_FAILURE);
    }

    printf("データを入力してください(終了は＾D)\n");
    rewind(stdin);
    g_pt = gakusei;
    while((scanf("%s %d", g_pt->name, &(g_pt->ten))) != EOF) {
        fprintf(gf_pt, "%-10s %3d", g_pt->name, g_pt->ten);
    }

    fseek(gf_pt, 0L, SEEK_SET);
    rewind(gf_pt);
    for(i=0; fscanf(gf_pt, "%10s %3d", gakusei[i].name, &(gakusei[i].ten)) != EOF; i++)
    printf("データを表示します\n");
    for(j=0; j<i; j++){
        w_goukei += g_pt->ten;
        printf("%10s %3d\n", g_pt->name, g_pt->ten);
        g_pt++;
    }
    printf("          %4d\n", w_goukei);

    memset(gakusei, 0, sizeof(gakusei));
    if(fclose(gf_pt) == EOF) {
        printf("FILE CLOSE ERROR\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}