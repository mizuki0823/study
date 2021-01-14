#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b ^= a ^= b)

union X{ int a[5]; int b[3]; };
union IntAndChar { unsigned long long num; char character; };


int main () {
    union X y;

    y.a[1] = 10;
    y.b[1]= 20;

    printf("y.a[1]=%d\n", y.a[1]);

    union IntAndChar intAndChar;

    intAndChar.character = 'A';
    printf("intAndChar.character=%d\n", intAndChar.character);
    printf("intAndChar.num=%16llo\n", intAndChar.num);

    intAndChar.num = 6500;
    printf("intAndChar.character=%d\n", intAndChar.character);
    printf("intAndChar.num=%16llo\n", intAndChar.num);
    
     intAndChar.character = 'A';
    printf("intAndChar.character=%d\n", intAndChar.character);
    printf("intAndChar.num=%16llo\n", intAndChar.num);

    return 0;
}