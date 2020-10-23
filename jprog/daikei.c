#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    double xa = 0, xb = M_PI;
    int n = 100;
    double h = (xb - xa) / (n - 1);
    double s = 0;
    //double x = xa;
    int i;
    //x += h;

    for(i=2; i<= n-1; i++){
        s += sin(xa + h * (i - 1));
        // s += sin(x); 上と下の計算は意味として同じ
        //x += h;
    }

    s *= 2;
    s += sin(xa);
    s += sin(xb);
    s *= (h / 2);

    printf("sin(x)をx=%lfからx=%lfまで積分した値は、%lfです\n", xa,xa,s);

    return 0;
}