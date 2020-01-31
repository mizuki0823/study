#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int f(char []);

int main () {
    char s[80];

    printf("入力： ");
    fgets(s, sizeof(s), stdin);
    s[strlen(s) - 1] = '\0';
    printf("出力１ = %d\n", strlen(s));
    printf("出力２ = %d\n", f(s));
    return 0;
}

int f(char str[]){
    int i, n = 0;

    for(i = strlen(str) - 1; i >= 0; i --)
        if(str[i] == ' ')
            n ++;

    return n + 1;
}