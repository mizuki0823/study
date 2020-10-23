#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

double disection (double (*f)(double), double a, double b, double eps);
double f1(double);
double f2(double);
double f3(double);

int main () {
    double alpha = disection(sin, -0.5, 1, 0.01);
    double al=disection(f1, -10, 10, 0.01);
    if(isnan(al) != 1){
        printf("sin(x)となるxは%f\n", alpha);
    }
    else{
        printf("解が存在しません \n");
    }

    double alpha2 = disection(f2, -0.5, 0.5, 0.001);
    if(isnan(alpha2) != 1){
        printf("f2(x)=0となるxは%f\n", alpha2);
    }
    else{
        printf("解が存在しません \n");
    }
    return 0;
}

double disection (double (*f)(double), double a, double b, double eps){

    if((*f)(a) * (*f)(b) > 0) {
        return NAN;
    }

    double m = (a+b)/2;
    while (fabs(a-b) >= eps){
        printf("a=%f, b=%f\n", a,b);
        m = (a+b)/2;
        if((*f)(m) == 0){
            return m;
        }
        if((*f)(a) * (*f)(m) < 0){
            b = m;
        }

        else if((*f)(m) * (*f)(b) < 0){
            a = m;
        }
    }
    
}

double f1(double x){
    return x*x*x*x*x + 2*x*x*x + (-5)*x + 10;
}

double f2(double x){
    return sin(x) + x*x;
}

