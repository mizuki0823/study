#include <stdio.h>

int main () {
    double n, b[200], z, p, w;
    int a[7], s;

    printf("初期値：");
    scanf("%lf", &n);

    s = n * n;

    for(int i = 0; i < 200; i++){
            
            a[0] = s / 10000000;
            a[1] = (s / 1000000) % 10;
            a[2] = (s / 100000)  % 10;
            a[3] = (s / 10000)   % 10;
            a[4] = (s / 1000)    % 10;
            a[5] = (s / 100)     % 10;
            a[6] = (s / 10)      % 10;
            a[7] = s % 10;

           s = a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5];
           b[i] = s / 9999.0;

           //printf("%d\n", s);
           s = s * s;
    }

    for(int j = 0; j < 100; j ++){
            z = b[j] * b[j] + b[j + 1] * b[j + 1];
            if(z < 1){
                ++p;
            }

            continue;
    }
     w = 4 * p / 100;
     printf("%lf\n", w);
    
    return 0;
}