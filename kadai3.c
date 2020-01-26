#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

void f( char );
int p1 = 0, p2 = 0;

int main () {
    char n;

    printf("入力");
    scanf("%c", &n);
    printf("出力");
    f(n);

    return 0;
}

void f(char c){
    if (c <= '9'){
        p1 ++;
        f(c + 2);
        p2 ++;
        putchar (c);
        if (p1 == p2)
            putchar('\n');
    }
}