#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

void f(char []);

int main () {
    char str[256];

    printf("入力");
    scanf("%s", str);
    f(str);
    printf("出力");
    printf("%s\n", str);

    return 0;
}

void f( char s[]){
    int i;

    for (i = 0; i < strlen( s ); i++ ){
        printf("\n");
        s[i] %= 10;
        printf("%d\n", s[i]);
        s[i] += '0';
        printf("%d\n", s[i]);
    }
}