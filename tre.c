#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    int i, *p1;
    i = 25;
    p1 = &i;

    char *p2;
    char f = 'A';
    p2 = &f;

    double s, *p3;
    s = 2.5;
    p3 = &s;

    printf("int=%d\n intアドレス(16)=%x\n intアドレス(10)=%d\n", i, p1, p1);
    printf("\n");

    printf("char=%c\n charアドレス(16)=%x\n charアドレス(10)=%d\n", f, p2, p2);
    printf("\n");

    printf("double=%lf\n doubleアドレス(16)%x\n doubleアドレス(10)=%d\n", s, p3, p3);
    printf("\n");

    return 0;
}