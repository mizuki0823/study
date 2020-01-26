#include <stdio.h>

int main () {
    int a[4];
    int min, max, z, n, b;

    n = 0;
    b = 0;
    z = 0;
    printf("正の整数（４桁）：");
    scanf("%d",&n);
    
    while(1){
        if(n == 0 || n == 6174){
            break;
        }

        else{
            a[0] = n / 1000;
            a[1] = (n / 100) % 10;
            a[2] = (n / 10)  % 10;
            a[3] = n % 10;

            for(int j = 0; j < 4; j++){
                for(int i = 0; i < 3; i++){
                    
                        if(a[i] >= a[i + 1]){
                            continue;
                        }
                        else{
                            z = a[i];
                            a[i] = a[i + 1];
                            a[i + 1] = z;
                        }
                }

            }

            max = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
            min = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
            n = max - min;
            b++;
        }
    }
    printf("%d\n",b);
    n = 0;
    return 0;
}
