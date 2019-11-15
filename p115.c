#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int souwa(int);
int main () {
    printf("1~10の総和は%dです\n", souwa(10));
    return 0;
}

int souwa(int n)
{
    if(n < 2)
        return 1;
    else
        return (n + souwa(n - 1));
}