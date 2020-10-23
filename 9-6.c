#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    union suuchi_format {
        char c_data[4];
        long l_data;
    } suuchi_data;
    int i;

    suuchi_data.l_data = 0x65734829;

    for(i=0; i<4; i++) {
        printf("%d:0x%x\n", i + 1, suuchi_data.c_data[i]);
    }

    return 0;
}