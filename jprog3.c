#include <stdio.h>
#include <stdlib.h>
int main () {
    double n, x, y, a, b, p;

    printf("n = ");
    scanf("%lf", &n);

    for(double i = 0; i <= n; i++){
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        b = x * x + y * y;
        if(b <= 1){
            p++;
        }

        continue;
    }
    a = 4 * p / n;


    printf("%lf\n", a);

    return 0;
}