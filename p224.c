#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
   unsigned char a[9]; 
    unsigned int x;
    printf("入力");
    scanf("%s", a);

    x == 0;
    for(int i = 0; i < 9; i++){
        x <<= 4;
        x |= ( a[i] - '0' );
    }
    
    printf("0x%08x\n", x);
    return 0;
}