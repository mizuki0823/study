#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int enen(int);
int main () {
    int n;
    printf("入力してください\n");
    scanf("%d",&n);
    printf("%d\n", enen(n));
    return 0;
}

int enen(int x)
{
    if (x == 1){
        return 2;
    }
    else{
        return 2 + enen(x - 1);
    }

}