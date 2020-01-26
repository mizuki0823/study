#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

void kuku(int);
int main () {
    int n;
    printf("入力");
    scanf("%d", &n);
    kuku(n);
    return 0;
}
void kuku(int x)
{

    int i;
    if(x > 9)
    return;
    else
    {

        kuku(x + 1);
        for(i = 1; i <= 9; i++)

            printf("%d ", i * x);
        
        printf("\n");

        
    }
} 
