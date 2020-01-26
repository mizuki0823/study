#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)


void print(int [], int);
int main () {
    int val[5] = {1, 2, 3, 4, 5};

    print( val, 5);
    print( val, 5);
    return 0;
}

void print(int x[5], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d\n", x[i]);
        x[i] *= 2;
    }    
}