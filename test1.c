#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int f(char []);
int p = 0, n = 0;

int main () {
    char s [80];

    printf("入力：");
    fgets(s, sizeof(s), stdin);
    s[strlen(s) - 1] = '\0';
    printf("出力 = %d\n", f(s));
    return 0;
}

int f(char str[]){
    if(p >= strlen(str))
        return n + 1;

    if(str[p] == ' ')
        n ++; 
    p ++;

    f(str);
}