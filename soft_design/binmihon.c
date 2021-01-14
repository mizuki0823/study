#include <stdio.h>

int bin(int, int);

int main() {
    int n, k;
    for(n=0; n<=20; ++n) {
        for(k=0; k<=20; ++k) {
            // printf("%d ", bin(n, k));
            printf("%c", bin(n, k)%2==0?' ':'*');
        }
        printf("\n");
    }
    return 0;
}

int bin(int n, int k) {
    if(k == 0)
        return 1;
    else if(n == k)
        return 1;
    else if(k > n)
        return 0;
    else
        return bin(n - 1, k - 1) + bin(n - 1, k);
}

int nonr_bin(int n, int k){
    
}
