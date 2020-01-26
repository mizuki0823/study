#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
    short data_a = 10;
    long data_b = 20;
    char data_c ;

    printf("%d + %ld = %ld\n", data_a, data_b, data_a + data_b);
    data_c = data_a + data_b;
    printf("%d + %ld = %ld\n", data_a, data_b, data_c);
    printf("sizeof(data_a) = %dバイト\n", sizeof(data_a));
    printf("sizeof(data_b) = %dバイト\n", sizeof(data_b));
    printf("sizeof(data_c) = %dバイト\n", sizeof(data_c));
    return 0;
    //型違うって怒られるんやけど
}