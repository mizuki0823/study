#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

double disection (double (*f)(double), double a, double b, double eps);
int nbisec (double (*f)(double), double a, double b, int n, double eps, double *answers);

int main () {
    double alpha = disection(sin, -0.5, 1, 0.01);

    if(isnan(alpha) != 1){
        printf("sin(x)となるxは%f\n", alpha);
    }
    else{
        printf("解が存在しません \n");
    }

    int n=10, count;
    double *anss = malloc(sizeof(double)*n);
    count = nbisec(sin, -10, 10, n, 0.001, anss);
    int i;
    for(int i=0; i<count; ++i ){
        printf("sin(x)の解%dは%f\n", i, anss[i]);
    }
    free(anss);
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
        if((*f)(a) == 0){
            return a;
        }
        if((*f)(b) == 0){
            return b;
        }
        
        if((*f)(a) * (*f)(m) < 0){
            b = m;
        }

        else if((*f)(m) * (*f)(b) < 0){
            a = m;
        }
    }
    
}

int nbisec (double (*f)(double), double a, double b, int n, double eps, double *answers){
    double ans, h;
    int count=0;
    h=(b-a)/n;
    for(int i=0; i<n; i++){
        ans = disection(f, a + h * i, a + h * (i + 1), eps);
        if(isnan(ans) != 1){
            *answers = ans;
            answers++;
            count++;
        }

    }
    return count;
}