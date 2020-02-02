#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

void f(int);

char s[80];

int main () {
    int n, i;

    printf("入力：");
    scanf("%d", &n);
    for(i = 0; i < sizeof(s); i++)
        s[i] = '\0';
    f(n);
    printf("出力：%s\n", s);
    return 0;
}

void f(int x){
    if(x > 0){
        s[x - 1] = '@' + x;
        f(x - 1);
    }
}