#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    struct l_data {
    char *namae;
    int toshi;
    struct l_data *l_pt;
};
    struct l_data chichi = {"Naoki", 58};
    struct l_data haha = {"Naomi", 56};
    struct l_data ane = {"Saeko", 25};
    struct l_data *l_top, *w_pt;

    l_top = &chichi;
    chichi.l_pt = &haha;
    haha.l_pt = &ane;
    ane.l_pt = NULL;

    w_pt = l_top;
    while(w_pt != NULL){
        printf("%sさん　年齢%d\n", w_pt->namae, w_pt->toshi);
        w_pt = w_pt->l_pt;
    }

    return 0;
}