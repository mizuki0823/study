#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

void star(int);

int main () {
    int a;

    printf("入力 : ");
    scanf("%d",&a);
    // printf("\n");
    star (a);
    
    return 0;
}

void star (int x) {
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < i; j++){
            printf("* ");
        }
        printf("\n");
    }
}

//int main () {
//    return 0;
//}
// => void main () {}
//void func () {
//}