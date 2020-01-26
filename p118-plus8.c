#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)


float average(int [], int);
int main () {
    int val[5] = {2, 7, 8, 1, 4};

    printf( "平均値 = %f\n", average( val, 5));
    return 0;
}

float average(int x[], int n)
{
    int i;
    float ave = 0;
    for (i = 0; i < n; i++)
        ave += x[i];
    return ave / n;
     
}