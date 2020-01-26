#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int val[5] = {1, 2, 3, 4, 5};
void print();
int main () {
    print();
    return 0;
}

void print()
{
    int i;
    for (i = 0; i < 5; i++)
        printf("%d\n", val[i]);
}