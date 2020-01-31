#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

char f(char []);

int main () {
    char s[3];

    printf("入力： ");
    scanf("%s", s);
    printf("出力： = %c\n", f(s));
    return 0;
}

char f(char str[]){
    char c1, c2;

    c1 = str[0] - '0';
    if(c1 > 9)
        c1 = str[0] - 'A' + 10;
    c2 = str[1] - '0';
    if(c2 > 9)
        c2 = str[1] - 'A' + 10;

    return c2 + (c1 << 4);
}