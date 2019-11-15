#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int gcm(int, int);
int main () {
        int a, b;
        printf("2つの数字を入力してください\n");
        scanf("%d%d", &a, &b);
        printf("最大公約数は%dです\n", gcm(a, b)); 
    return 0;
}

int gcm(int x, int y)
{
    int remainder; 
    remainder = x % y;
    
    if(remainder == 0)
        return y;
    else
    {
        x = y;
        y = remainder;

        return (gcm(x , y));
    }
}