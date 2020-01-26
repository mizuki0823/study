#include <stdio.h>

int main () {
    int n, a[7], s;

    printf("初期値：");
    scanf("%d", &n);

    s = n * n;

    for(int i = 0; i < 100; i++){
            
            a[0] = s / 10000000;
            a[1] = (s / 1000000) % 10;
            a[2] = (s / 100000)  % 10;
            a[3] = (s / 10000)   % 10;
            a[4] = (s / 1000)    % 10;
            a[5] = (s / 100)     % 10;
            a[6] = (s / 10)      % 10;
            a[7] = s % 10;

           s = a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5];

           printf("%d\n", s);
           s = s * s;
    }
    
    return 0;
}