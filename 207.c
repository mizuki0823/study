#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
    int suuchi_1 = 100, suuchi_2 = 3;
    double kekka;

    kekka = suuchi_1 / suuchi_2;
    printf("キャストなし %f\n", kekka);
    kekka = (double) (suuchi_1 / suuchi_2);
    printf("キャストあり %f\n", kekka);
    return 0;
}