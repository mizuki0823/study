#include <stdio.h>
#include <math.h>

double trapezoid(double xa, double xb, int n, double (*f)(double));
double x_2(double);

int main() {
    double xa = 0, xb = M_PI;
    int n = 100000;
    double s = trapezoid(xa, xb, n, sin);
    printf("sin(x)をx=%lfからx=%lfまで積分した値は，%lfです\n", xa, xb, s);
    double s2 = trapezoid(xa, xb, n, cos);
    printf("cos(x)をx=%lfからx=%lfまで積分した値は，%lfです\n", xa, xb, s2);
    printf("x^2をx=%lfからx=%lfまで積分した値は，%lfです\n", 0.0, 1.0, trapezoid(0.0, 1.0, 1000, x_2));
    return 0;
}

double trapezoid(double xa, double xb, int n, double (*f)(double)) {
    double h = (xb - xa) / (n - 1);
    double s = 0;
    int i;
    for(i=2; i <= n-1; ++i) {
        s += (*f)(xa + h * (i-1));
    }
    s *= 2;
    s += (*f)(xa);
    s += (*f)(xb);
    s *= (h / 2);
    return s;
}

double x_2(double x) {
    return x*x;
}