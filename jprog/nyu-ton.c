#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

double newton(double(*f)(double),double(*df)(double), double x0,double eps, int nmax);
double f1(double x);
double f1d(double y);

int main () {
    double xn = newton(f1, f1d, 3.15, 0.001, 100);

     if(isnan(xn) != 1){
        printf("f1(x)の解は%f\n", xn);
    }
    else{
        printf("解が存在しません \n");
    }


    return 0;
}

double newton(double(*f)(double),double(*df)(double), double x0,double eps, int nmax){
    if(nmax < 1){
        return NAN;
    }

    double ho=f(x0)/df(x0);
    if(fabs(ho) < eps){
        return x0;
    }

    double xnp1=x0 - ho;
    return newton(f, df, xnp1, eps, nmax -1);
}

double f1(double x){
    double f;

    f = sin(x);
    return f;
}

double f1d(double y){
    double fx;
    fx = cos(y);
    return fx;
}
