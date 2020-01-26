#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
    char bit_d = 0x26; 
    int i;

    for(i = 1; i < 9; i++){
        printf("%d:10進:%+4d 16進:%02x\n", i, bit_d, bit_d);
        bit_d = (bit_d << 1);
    }
    return 0;
}