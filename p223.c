#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int main () {
    char moji_b, mask_b = 0x20; //32 100000

    printf("英文字１文字入力");
    scanf("%c", &moji_b);
    printf("入力された文字：%c,変換した文字：%c\n", moji_b, moji_b ^ mask_b);
    return 0;
}