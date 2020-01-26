#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
    char bit_1 = 0x26;
    char bit_2 = 0x35;

    printf("NOT: %x\n", ~bit_1);
    printf("AND: %x\n", bit_1 & bit_2);
    printf("OR : %x\n", bit_1 | bit_2);
    printf("XOR: %x\n", bit_1 ^ bit_2);

    return 0;
}