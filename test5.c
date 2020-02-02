#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

unsigned short f(char []);

int main () {
    char s[17];

    printf("入力：");
    scanf("%s", s);
    printf("出力：%u\n", f(s));
    return 0;
}

unsigned short f(char str[]){
    static int i = 0;
    static unsigned short z = 0;

    if(i >= strlen(str))
        return z;
    else{
        z <<= 1;
        z += (str[i] - '0');
        i ++;
        f(str);
    }
}