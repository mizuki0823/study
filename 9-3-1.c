#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    struct shiken_format{
        char *namae;
        int eigo;
        int kokugo;
    };
    struct shiken_format gakusei[] = {
        {"Andou", 65, 70},
        {"Imai", 80, 78},
        {"Ueno", 90, 58},
        {"Endoi", 59, 66},
        {"Oono", 72, 91},
    };
    int i, goukei, eigo_kei = 0, kokugo_kei = 0;
    struct shiken_format *g_pt;
    g_pt = gakusei;
    for(i = 0; i < 5; i++){
        goukei = (gakusei + i)->eigo + (gakusei +i)->kokugo;
        eigo_kei += (gakusei + i)->eigo;
        kokugo_kei += (gakusei + i)->kokugo;
        printf("%sさん　合計：%d\n", (gakusei + i)->namae, goukei);
    }
    printf("英語合計　：%d　国語合計　：%d\n", eigo_kei, kokugo_kei);
    return 0;
}