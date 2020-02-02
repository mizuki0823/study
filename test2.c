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

    printf("入力：");
    scanf("%s", s);
    printf("出力：%c\n", f(s));

    return 0;
}

char f(char str[]){
    char c;
    static char z = 0;
    int sn;

    sn = strlen(str);
    z <<= 4;

    c = str[0] - '0';
    if(c > 9)
        c = str[0] - 'A' + 10;

    z += c;
    str[0] = str[1];
    str[1] = '\0';

    if(sn < 2)
        return z;

    f(str);
}