#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

int main () {
    char s[12];

    printf("文字列：");
    fgets(s, sizeof(s), stdin);
    printf("s: %s", s); //fgetsには改行も含まれる・CTRL＋DでNULLを返す
    return 0;
    
}
