#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

void f(unsigned short, char[]);

int main () {
    unsigned short n;
    char s[17];
    int i;

    printf("入力：");
    scanf("%u", &n);
    for (i = 0; i < sizeof(s); i ++)
        s[i] = '\0';
    f(n, s);
    printf("出力：%s\n", s);

    return 0;
}

void f(unsigned short num, char str[]){
    static int k = 0;

    if(num > 0){
        f(num / 2, str);
        str[k] = (num & 1) + '0';
        k ++;
    }

    if(k == 0)
        strcpy(str, "0");
}