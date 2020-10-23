#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int nbisec (double (*f)(double), double a, double b, int n, double eps, double *answers);

int main () {
    int alpha = nbisec(sin, -0.5, 1, 5, 0.01, 5);

    


    return 0;
}

int nbisec (double (*f)(double), double a, double b, int n, double eps, double *answers){

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
