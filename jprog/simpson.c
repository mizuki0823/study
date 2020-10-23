#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

double simpson(double xa, double xb, int n, double (*f)(double));
double x_2(double);

int main () {
   double xa = 0, xb = M_PI;
    int n = 100001;
    double s = simpson(xa, xb, n, sin);
    printf("sin(x)をx=%lfからx=%lfまで積分した値は，%lfです\n", xa, xb, s);
    double s2 = simpson(xa, xb, n, cos);
    printf("cos(x)をx=%lfからx=%lfまで積分した値は，%lfです\n", xa, xb, s2);
    printf("x^2をx=%lfからx=%lfまで積分した値は，%lfです\n", 0.0, 1.0, simpson(0.0, 1.0, n, x_2));
    return 0;
}

double simpson(double xa, double xb, int n, double (*f)(double)) {
    double h = (xb - xa) / (n - 1);
    double s = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0; //←第ｎ項
    int i;
    s1 = f(xa);
    for(i=1; i<=(n-1)/2; ++i){
        s2 += f(xa + h * (2*i-1));
    }
    s2 *= 4;

    for(i=1; i<=(n-1)/2-1; i++){
        s3 += f(xa + h * (2*i));
    }

    s3 *= 2;
    s4 = f(xb);
    s = s1 + s2 + s3 + s4;
    s *= h / 3;
   
    return s;
}

double x_2(double x) {
    return x*x;
}