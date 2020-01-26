#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define abs(a) (a>0?a:-a)
#define swap(a,b) (a ^= b;b ^= a;a ^= b)

int judege(unsigned short);
unsigned short int change(char []);

int main () {
    unsigned short int mohan, kaito, seikai;
    char s1[17], s2[17];
    int i;

    printf("模範解答：");
    scanf("%s", s1);
    mohan = change(s1);

    while (1){
        printf("生徒の回答：");
        if(scanf ("%s", s2) == EOF)
            break;
        kaito = change(s2);
        seikai = judge(mohan, kaito);
        printf("正解数： %d\n", seikai);
    }
    
    return 0;
}

int change(char a[17]){
    unsigned short int x;
    for(int i = 0; i < strlen(a); i++){
        x <<= 1;
        x |= (a[i] - '0');
    }
}

int judege(unsigned short m, unsigned short k){
    unsigned short xor;
    int i, s = 0;
    xor = m ^ k;
    for(i = 0; i < 16; i++){
        if(! (xor & 1))
            s ++;
        xor >>= 1;
    }
    return s;
}